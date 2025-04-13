#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define CLEAR "cls"

void clearScreen()
{
    system(CLEAR);
}
struct Activity
{
    int start, end, index;
};

bool compare(const Activity &a, const Activity &b)
{
    return a.end < b.end;
}
void printActivities(const vector<Activity>& activities, const vector<bool>& selected, int current = -1)
{
    cout << "Index\tStart\tEnd\tSelected\n";
    cout << "----------------------------------\n";
    for (size_t i = 0; i < activities.size(); ++i)
    {
        cout << activities[i].index << "\t" << activities[i].start << "\t" << activities[i].end << "\t";
        if (i == current) cout << "[Checking]";
        else if (selected[i]) cout << "Yes";
        else cout << "No";
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    clearScreen();
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter start and end time of activity " << i + 1 << ": ";
        cin >> activities[i].start >> activities[i].end;
        activities[i].index = i + 1;
    }
    sort(activities.begin(), activities.end(), compare);
    vector<bool> selected(n, false);

    int lastEnd = 0;
    cout << "\nStarting activity selection...\n";
    Sleep(1000);

    for (int i = 0; i < n; ++i)
    {
        clearScreen();
        cout << "Checking activity " << activities[i].index << ": (" << activities[i].start << ", " << activities[i].end << ")\n\n";
        printActivities(activities, selected, i);
        Sleep(1000);

        bool isSelected = false;
        if (activities[i].start >= lastEnd)
        {
            selected[i] = true;
            lastEnd = activities[i].end;
            isSelected = true;
        }
        clearScreen();
        cout << "Activity " << activities[i].index << " was " << (isSelected ? "selected." : "not selected.") << "\n\n";
        printActivities(activities, selected);
        Sleep(1000);
    }
    clearScreen();
    cout << "Activity selection complete.\n";
    cout << "Selected activities:\n";
    for (size_t i = 0; i < activities.size(); ++i)
    {
        if (selected[i])
        {
            cout << "Activity " << activities[i].index << ": (" << activities[i].start << ", " << activities[i].end << ")\n";
        }
    }
    return 0;
}
