#include <bits/stdc++.h>

using namespace std;

struct Student {
  int scores[5]; // scores in the order: Chinese, English, Mathematics, Science,
                 // Social Studies

  // Calculate the total score of the student
  int total_score() const {
    int total = 0;
    for (int i = 0; i < 5; ++i) {
      total += scores[i];
    }
    return total;
  }

  // Calculate the number of passing subjects
  int passing_subjects() const {
    int passing = 0;
    for (int i = 0; i < 5; ++i) {
      if (scores[i] >= 60) {
        ++passing;
      }
    }
    return passing;
  }
};

// Custom comparator function for sorting the students
bool compare_students(const Student &a, const Student &b) {
  // Rule 1: Total score comparison
  if (a.total_score() != b.total_score()) {
    return a.total_score() > b.total_score();
  }

  // Rule 2: Passing subjects comparison
  if (a.passing_subjects() != b.passing_subjects()) {
    return a.passing_subjects() > b.passing_subjects();
  }

  // Rule 3: Compare scores subject-wise (Chinese, English, Math, Science,
  // Social Studies)
  for (int i = 0; i < 5; ++i) {
    if (a.scores[i] != b.scores[i]) {
      return a.scores[i] > b.scores[i];
    }
  }

  // If all scores are the same, they are considered equal (though the problem
  // guarantees no tie)
  return false;
}

int main() {
  int n;
  cin >> n; // Number of students

  vector<Student> students(n);

  // Input the scores for each student
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> students[i].scores[j];
    }
  }

  // Sort the students based on the custom comparator
  sort(students.begin(), students.end(), compare_students);

  // Output the sorted students' scores
  for (const auto &student : students) {
    for (int j = 0; j < 5; ++j) {
      cout << student.scores[j] << " ";
    }
    cout << endl;
  }

  return 0;
}
