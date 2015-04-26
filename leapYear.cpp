#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> M({{"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11} , {"December", 12}});


void getDetail(const string &date, int &month, int &day, int &year) {
    int idx = 0;
    while (idx < date.size() && date[idx] != ' ') ++idx;
    month = M[date.substr(0, idx)];
    int tmp = ++idx;
    while (idx < date.size() && date[idx] != ',') ++idx;
    day = atoi(date.substr(tmp, idx - tmp).c_str());
    year = atoi(date.substr(idx + 2).c_str());
}

bool isLeapYear(const int &year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int kYearNum(const int &begYear, const int &endYear, const int &k) {
    int beg = begYear + 1, end = endYear - 1;
    while (beg <= end) {
        if (beg % k == 0) break;
        ++beg;
    }
    if (beg > end) return 0;
    while (end >= beg) {
        if (end % k == 0) break;
        --end;
    }
    return (end - beg) / k + 1;
}

int leapYearNum(const string &beg, const string &end) {
    int begMonth, begDay, begYear, endMonth, endDay, endYear;
    getDetail(beg, begMonth, begDay, begYear);
    getDetail(end, endMonth, endDay, endYear);
    int ret = kYearNum(begYear, endYear, 4) - kYearNum(begYear, endYear, 100) + kYearNum(begYear, endYear, 400);
    if (begYear < endYear) {
        if (isLeapYear(begYear) && begMonth <= 2) ++ret;
        if (isLeapYear(endYear) && ((endMonth > 2) || (endMonth == 2 && endDay == 29))) ++ret;
    }
    else if (begYear == endYear && isLeapYear(begYear)) {
        int days[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
        int dest = days[2] + 29, left = days[begMonth] + begDay, right =days[endMonth] + endDay;
        if (left <= dest && dest <= right) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    int T;
    (cin>>T).get();
    int num = 1;
    while (num <= T) {
        string beg, end;
        getline(cin, beg);
        getline(cin, end);
        cout<<"Case #"<<num++<<": "<<leapYearNum(beg, end)<<endl;
    }
    return 0;
}
