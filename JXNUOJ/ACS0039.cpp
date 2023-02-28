#include <bits/stdc++.h>

using namespace std;

class time_tick {
public:
    time_tick();
    time_tick(int tick);
    time_tick(int h, int m, int s);
    void set_hms(int h, int m, int s);
    void get_hms(int *h, int *m, int *s) const;
    int get_tick() const;

    time_tick operator+(int ticks) const;
    time_tick operator-(int ticks) const;
    time_tick & operator=(const int &ticks);
    time_tick & operator+=(const int &ticks);

    bool operator<(const time_tick &rval) const;
    bool operator>(const time_tick &rval) const;
    bool operator<=(const time_tick &rval) const;
    bool operator>=(const time_tick &rval) const;
private:
    int tick;
};

time_tick::time_tick() {
    *this = 0;
}

time_tick::time_tick(int tick) {
    *this = tick;
}

time_tick::time_tick(int h, int m, int s) {
    this->set_hms(h, m, s);
}

void time_tick::set_hms(int h, int m, int s) {
    int tick = 0;
    tick += h * 3600;
    tick += m * 60;
    tick += s;
    this->tick = tick;
}

void time_tick::get_hms(int *h, int *m, int *s) const {
    int tick = this->tick;
    if (h != nullptr) {
        *h = tick / 3600;
    }
    tick = tick % 3600;
    if (m != nullptr) {
        *m = tick / 60;
    }
    tick = tick % 60;
    if (s != nullptr) {
        *s = tick;
    }
}

int time_tick::get_tick() const {
    return this->tick;
}

time_tick time_tick::operator+(int tick) const {
    return time_tick(this->tick + tick);
}

time_tick time_tick::operator-(int tick) const {
    return time_tick(this->tick - tick);
}

time_tick & time_tick::operator=(const int &tick) {
    this->tick = tick;
    return *this;
}

time_tick & time_tick::operator+=(const int &tick) {
    this->tick += tick;
    return *this;
}

bool time_tick::operator<(const time_tick &rval) const {
    return this->get_tick() < rval.get_tick();
}

bool time_tick::operator>(const time_tick &rval) const {
    return this->get_tick() > rval.get_tick();
}

bool time_tick::operator<=(const time_tick &rval) const {
    return this->get_tick() <= rval.get_tick();
}

bool time_tick::operator>=(const time_tick &rval) const {
    return this->get_tick() >= rval.get_tick();
}

struct clock_set {
    time_tick begin_tick;
    int hold;
    int rep;
};

struct clock_single {
    time_tick begin_tick;
    time_tick end_tick;
};

int main() {
    int n;
    cin >> n;

    vector<clock_set> clocksets(n);
    for (int i=0; i<n; i++) {
        int h, m, s, hold, rep;
        scanf("%d-%d-%d %d %d\n", &h, &m, &s, &hold, &rep);
        clocksets[i].begin_tick = time_tick(h, m, s);
        clocksets[i].hold = hold;
        clocksets[i].rep = rep;
    }

    time_tick final_tick;
    int fh, fm, fs;
    scanf("%d-%d-%d", &fh, &fm, &fs);
    final_tick.set_hms(fh, fm, fs);

    vector<clock_single> clocks;
    for (auto iter = clocksets.begin(); iter < clocksets.end(); iter++) {
        time_tick begin_time = iter->begin_tick;
        while (begin_time < final_tick) {
            clock_single cl;
            cl.begin_tick = begin_time;
            cl.end_tick = min(begin_time + iter->hold, final_tick);

            begin_time += iter->hold + iter->rep;
            clocks.push_back(cl);
        }
    }

    sort(clocks.begin(), clocks.end(), [](const clock_single &a, const clock_single &b) {
        return a.begin_tick < b.begin_tick;
    });

    vector<clock_single> merged_clocks;
    clock_single processing_clock = clocks[0];
    for (auto iter = clocks.begin()+1; iter < clocks.end(); iter++) {
        if (iter->begin_tick <= processing_clock.end_tick) {
            processing_clock.end_tick = max(iter->end_tick, processing_clock.end_tick);
        } else {
            merged_clocks.push_back(processing_clock);
            processing_clock = *iter;
        }
    }
    merged_clocks.push_back(processing_clock);

    int sec_count = 0;
    for (auto iter = merged_clocks.begin(); iter < merged_clocks.end(); iter++) {
        sec_count += iter->end_tick.get_tick() - iter->begin_tick.get_tick();
    }
    int result = final_tick.get_tick() - sec_count - merged_clocks[0].begin_tick.get_tick();
    cout << result << endl;
    return 0;
}