#include <bits/stdc++.h>
using namespace std;

class Result_cal
{
public:
    string course_name;
    int credit;
    int attendance, class_performance;
    vector<int> ct;
    int mid, final_exam;

    Result_cal()
    {
        cout << "\nEnter course name: ";
        getline(cin, course_name);

        cout << "Enter credit: ";
        cin >> credit;

        cout << "Enter attendance marks(out of 10): ";
        cin >> attendance;

        cout << "Enter class performance marks(out of 10): ";
        cin >> class_performance;

        cout << "Enter 4 CT marks: " << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "CT " << i + 1 << " :";
            int temp;
            cin >> temp;
            ct.push_back(temp);
        }

        cout << "Enter mid marks (out of 40): ";
        cin >> mid;

        cout << "Enter final marks (out of 100) ";
        cin >> final_exam;
    }

    double ctAverage()
    {
        vector<int> temp = ct;
        sort(temp.begin(), temp.end());
        return (temp[1] + temp[2] + temp[3]) / 3.0;
    }

    double totalMarks()
    {
        return attendance + class_performance +
               ctAverage() + mid / 2.0 + final_exam / 2.0;
    }

    double gpa()
    {
        double m = totalMarks();
        if (m >= 80)
            return 4.00;
        else if (m >= 75)
            return 3.75;
        else if (m >= 70)
            return 3.50;
        else if (m >= 65)
            return 3.25;
        else if (m >= 60)
            return 3.00;
        else if (m >= 55)
            return 2.75;
        else if (m >= 50)
            return 2.50;
        else if (m >= 45)
            return 2.25;
        else if (m >= 40)
            return 2.00;
        else
            return 0.00;
    }

    void show()
    {
        cout << "\nCourse: " << course_name << endl;
        cout << "Total Marks: " << fixed << setprecision(2)
             << totalMarks() << endl;
        cout << "GPA: " << fixed << setprecision(2)
             << gpa() << endl;
    }
};

int main()
{
    int n;
    cout << "How many courses? ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Result_cal> courses;

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Course " << i + 1 << " ---" << endl;
        courses.push_back(Result_cal());
    }

    cout << "\n\n========== RESULTS ==========" << endl;

    double total_credit = 0, weighted_gpa = 0;

    for (auto &c : courses)
    {
        c.show();
        total_credit += c.credit;
        weighted_gpa += c.gpa() * c.credit;
    }

    cout << "\n=============================" << endl;
    cout << "Overall CGPA: " << fixed << setprecision(2)
         << weighted_gpa / total_credit << endl;

    return 0;
}