#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
  int m, n;
  string nameA, nameB, queryType;

  cin >> m;

  map<string, set<string>> network;

  // Input the names
  for (int i = 0; i < m; i++) {
    string person;
    cin >> person;
    network[person] = set<string>();
  }

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> queryType;

    if (queryType == "MakeFriend") {
      // MakeFriend NameA NameB
      cin >> nameA >> nameB;
      network[nameA].insert(nameB);
      network[nameB].insert(nameA);
    } else if (queryType == "UnFriend") {
      // UnFriend NameA NameB
      cin >> nameA >> nameB;
      network[nameA].erase(nameB);
      network[nameB].erase(nameA);
    } else if (queryType == "ListFriend") {
      // ListFriend NameA
      cin >> nameA;
      if (network[nameA].empty()) {
        cout << endl;
      } else {
        for (const string &friendName : network[nameA]) {
          cout << friendName << " ";
        }
        cout << endl;
      }
    }
  }

  return 0;
}
