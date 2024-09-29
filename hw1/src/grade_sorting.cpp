#include <bits/stdc++.h>
using namespace std;

struct Student {
  vector<int> scores; // Stores the scores for each student
  int id;             // The student's ID (0-based)
  bool exceptional;   // Whether the student scores >=90 in all subjects
  int total;          // The total score
};

// Custom comparator function to sort students based on the rules
bool compare(const Student &a, const Student &b) {
  // Rule 1: Exceptional Performance Priority
  if (a.exceptional != b.exceptional)
    return a.exceptional > b.exceptional;
  // Rule 2: Total Score Priority
  if (a.total != b.total)
    return a.total > b.total;
  // Rule 3: Subject-wise Priority
  return a.scores > b.scores;
}

int main() {
  int n;
  cin >> n;
  vector<Student> students(n);

  for (int i = 0; i < n; ++i) {
    students[i].id = i;
    students[i].total = 0;
    students[i].exceptional = true;
    for (int j = 0; j < 5; ++j) {
      int score;
      cin >> score;
      students[i].scores.push_back(score);
      students[i].total += score;
      if (score < 90)
        students[i].exceptional = false;
    }
  }

  // Sort the students based on the custom comparator
  sort(students.begin(), students.end(), compare);

  // Output the ranks
  vector<int> ranks(n);
  for (int i = 0; i < n; ++i) {
    ranks[students[i].id] = i + 1; // Store the 1-based rank
  }
  for (int i = 0; i < n; ++i) {
    cout << ranks[i] << " ";
  }
  cout << endl;

  return 0;
}

