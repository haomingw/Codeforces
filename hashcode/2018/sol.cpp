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

const int inf = 1e9;
const int maxn = 1e5 + 5;
int height, width, C, N, bonus, T, total;
int used[maxn];

struct Ride {
    int sx, sy, tx, ty, start, end, index;

    Ride(int a, int b, int x, int y, int s, int f, int index): sx(a), sy(b), tx(x), ty(y), start(s), end(f), index(index) {}

    int distance() {
        return abs(tx - sx) + abs(ty - sy);
    }

    bool operator < (const Ride& b) {
        if (start == b.start) return end < b.end;
        return start < b.start;
    }
};

struct Car {
    int now, x, y, point;
    vector<int> rides;
    Car(): now(0), x(0), y(0), point(0) {}

    int take(Ride& ride) {
        assert(!used[ride.index]);
        used[ride.index] = true;
        rides.push_back(ride.index);
        int s = score(ride);
        total += s, point += s;

        now += toStartPoint(ride);
        now = max(now, ride.start);
        now += ride.distance();
        x = ride.tx, y = ride.ty;

        return x;
    }

    int fakeTake(Ride& ride) {
        rides.push_back(ride.index);
        int s = score(ride);
        point += s;

        now += toStartPoint(ride);
        now = max(now, ride.start);
        now += ride.distance();
        x = ride.tx, y = ride.ty;

        return x;
    }

    int score(Ride& ride) {
        int start = ride.start, end = ride.end;
        int current = now + toStartPoint(ride);
        current = max(current, start);
        int score = 0;
        if (current == start) score += bonus;
        int d = ride.distance();
        score += d, current += d;
        if (current <= end && current <= T + 1) return score;
        return 0;
    }

    int toStartPoint(Ride& ride) {
        return abs(x - ride.sx) + abs(y - ride.sy);
    }

    int evaluate(Ride& ride) {
        int d = toStartPoint(ride);
        int arrivingTime = now + d;
        return d + max(ride.start - arrivingTime, 0);
    }

    void print() {
        printf("%d ", SZ(rides));
        for (auto& ride : rides)
            printf("%d ", ride);
        printf("\n");
    }

    void clear() {
        for (int x : rides) used[x] = false;
        rides.clear();
        total -= point;
        point = 0;
        now = 0;
        x = 0, y = 0;
    }
};

vector<Ride> rides, profitRides;
vector<Car> cars;

void getProfitableRides() {
    // insure to get most profitable rides
    Car car = Car();
    vector<pii> ranking;
    for (auto& ride : rides) {
        ranking.push_back(MP(car.score(ride), ride.index));
    }
    sort(ALL(ranking));
    reverse(ALL(ranking));
    for (auto& p : ranking) {
        profitRides.push_back(rides[p.second]);
    }
}

void dispatchProfitableRides() {
    int dispatched = 0;
    for (auto& ride : profitRides) {
        int best = 0, index = 0, minLoss = inf;
        REP(i, C) {
            Car car = cars[i];
            int score = car.score(ride);
            if (score > best || (score == best && car.evaluate(ride) < minLoss))
                best = score, index = i, minLoss = min(minLoss, car.evaluate(ride));
        }
        if (best > 0) {
            dispatched++;
            cars[index].take(ride);
        }
    }
    clog << "dispatched profitable rides: " << dispatched << " / " << N << endl;
}

int calculate(vector<int>& r) {
    Car car = Car();
    for (int x : r) {
        car.fakeTake(rides[x]);
    }
    return car.point;
}

void insertAt(vector<int>& r, int pos, int element) {
    r.insert(r.begin() + pos, element);
}

void removeAt(vector<int>& r, int pos) {
    r.erase(r.begin() + pos);
}

void localSearch() {
    int cnt = 0;
    vector<int> solution;
    for (auto& car : cars) {
        int before = car.point;
        solution.clear();
        for (int x : car.rides) solution.push_back(x);
        bool changed = false;
        // TBD
        for (auto& ride : profitRides) if (!used[ride.index]) {
            REP(j, SZ(solution) + 1) {
                insertAt(solution, j, ride.index);
                int current = calculate(solution);
                if (current > before) {
                    before = current;
                    changed = true;
                    cnt++;
                    break;
                }
                removeAt(solution, j);
            }
        }
        if (changed) {
            // for (int x : car.rides) clog << x << " "; clog << endl;
            // for (int x : solution) clog << x << " "; clog << endl;
            car.clear();
            for (int x : solution)
                car.take(rides[x]);
        }
    }
    clog << "inserted " << cnt << " rides" << endl;
}

void greedy() {
    getProfitableRides();
    dispatchProfitableRides();
    localSearch();
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
        rides.push_back(Ride(a, b, x, y, s, f, i));
    }
    REP(i, C) {
        cars.push_back(Car());
    }

    greedy();

    int rds = 0;
    for (auto& car : cars) {
        car.print();
        rds += car.rides.size();
    }
    clog << "rides: " << rds  << " / " << N << endl;
    clog << "score: " << total << endl;

    return 0;
}
