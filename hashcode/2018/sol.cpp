#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

#define REPP(i,a,b) for(int i=(a); i < (b); ++i)
#define REP(i,a) for(int i = 0; i < (a); ++i)
#define PER(i,a) for(int i = (a) - 1; i >= 0; --i)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair

typedef long long ll;
typedef pair<int, int> pii;

struct Point {
    int x, y;
    Point(int x, int y): x(x), y(y) {}

    int to(const Point& b) {
        return abs(x - b.x) + abs(y - b.y);
    }
};

ostream& operator << (ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

struct Ride {
    Point source, target;
    int start, end, latestStart, index, carIndex;
    Ride(int a, int b, int x, int y, int s, int f, int index): source(Point(a, b)), target(Point(x, y)), start(s), end(f), index(index) {
        latestStart = end - distance();
        carIndex = -1;
    }

    int distance() {
        return source.to(target);
    }
};

ostream& operator << (ostream& out, const Ride& ride) {
    out << "ride #" << ride.index << ", from " << ride.source << " to " << ride.target;
    return out;
}

struct Car {
    int freeTime;
    Point position;
    bool occupied;
    Car(): position(Point(0, 0)) {
        occupied = false;
        freeTime = 0;
    }
};

struct Event {
    const static int FINISH = 1;
    const static int START = 2;
    const static int LATEST = 3; // now or never

    int type, rideIndex, time;
    Event(int type, int rideIndex, int time): type(type), rideIndex(rideIndex), time(time) {
        assert(type > 0 && type < 4);
    }
};

bool operator > (const Event& a, const Event& b) {
    if (a.time != b.time) return a.time > b.time;
    return a.type > b.type;
}

const int inf = 1e9;
const int maxn = 1e5 + 5;
int height, width, C, N, bonus, T, score, rds;
int used[maxn];
vector<int> ans[maxn];

vector<Ride> rides;
vector<Car> cars;
priority_queue<Event, vector<Event>, greater<Event> > events;
priority_queue<int, vector<int>, greater<int> > finishes;

void finish(Event& event) {
    Ride ride = rides[event.rideIndex];
    int carIndex = ride.carIndex;
    assert(carIndex >= 0);
    assert(cars[carIndex].occupied);
    cars[carIndex].occupied = false;
    cars[carIndex].position = ride.target;
    cars[carIndex].freeTime = event.time;
    ans[carIndex].push_back(ride.index);
    finishes.pop();
    score += ride.distance();
}

int findClosestCar(Ride& ride, int time) {
    int best = -1, minArrive = inf;
    REP(i, C) if (!cars[i].occupied) {
        int arrive = cars[i].freeTime + cars[i].position.to(ride.source);
        if (arrive > time) continue;
        if (arrive < minArrive) minArrive = arrive, best = i;
    }
    return best;
}

void dispatch(Event& event) {
    Ride ride = rides[event.rideIndex];
    int carIndex = findClosestCar(ride, event.time);
    if (carIndex == -1) {
        int nextTime = event.time + 1; // no car can finish this event on time, postpone
        if (SZ(finishes) == C) {
            nextTime = finishes.top(); // to ensure there is at least one car available for the event to be created
        }
        if (nextTime < ride.latestStart) {
            events.push(Event(Event::START, ride.index, nextTime));
        }
        return;
    }
    assert(!cars[carIndex].occupied);
    cars[carIndex].occupied = true;
    rides[ride.index].carIndex = carIndex;
    used[ride.index] = true;
    int finishTime = cars[carIndex].freeTime + cars[carIndex].position.to(ride.source);
    finishTime = max(finishTime, event.time);
    finishTime += ride.distance();
    finishes.push(finishTime);
    events.push(Event(Event::FINISH, ride.index, finishTime));

    if (event.time == ride.start) score += bonus;
}

void print() {
    REP(i, C) {
        printf("%d", SZ(ans[i]));
        rds += SZ(ans[i]);
        for (int x : ans[i]) printf(" %d", x);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef LOCAL
    assert(argc == 2);
    string input = argv[1];
    assert(SZ(input) > 3 && input.substr(SZ(input) - 3) == ".in");
    string output = input.substr(0, input.size() - 3) + ".out";

    freopen(input.c_str(), "r", stdin);
    freopen(output.c_str(), "w", stdout);
#endif
    cin >> height >> width >> C >> N >> bonus >> T;
    int a, b, x, y, s, f;
    REP(i, N) {
        cin >> a >> b >> x >> y >> s >> f;
        Ride ride = Ride(a, b, x, y, s, f, i);
        rides.push_back(ride);
        int startTime = max(a + b, s);
        if (startTime < ride.latestStart)
            events.push(Event(Event::START, i, startTime));
        events.push(Event(Event::LATEST, i, ride.latestStart));
    }
    REP(i, C) {
        cars.push_back(Car());
    }

    while (!events.empty()) {
        Event event = events.top(); events.pop();
        if (event.type == Event::FINISH) {
            finish(event);
            continue;
        }
        if (used[event.rideIndex]) continue;
        dispatch(event);
    }
    print();

    clog << "rides: " << rds  << " / " << N << endl;
    clog << "score: " << score << endl;

    return 0;
}