#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int totalLanguages, vector<vector<int>>& userLanguages, vector<vector<int>>& friendships) {
        unordered_set<int> usersToTeach;

        // Step 1: Identify users who can't communicate
        for (auto& friendship : friendships) {
            int user1 = friendship[0] - 1; // Convert to 0-based index
            int user2 = friendship[1] - 1;
            bool canCommunicate = false;

            for (int lang1 : userLanguages[user1]) {
                for (int lang2 : userLanguages[user2]) {
                    if (lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if (canCommunicate) break;
            }

            if (!canCommunicate) {
                usersToTeach.insert(user1);
                usersToTeach.insert(user2);
            }
        }

        // Step 2: Try teaching each language
        int minUsersToTeach = userLanguages.size() + 1;

        for (int language = 1; language <= totalLanguages; language++) {
            int count = 0;

            for (int user : usersToTeach) {
                bool knowsLanguage = false;
                for (int lang : userLanguages[user]) {
                    if (lang == language) {
                        knowsLanguage = true;
                        break;
                    }
                }
                if (!knowsLanguage) count++;
            }

            minUsersToTeach = min(minUsersToTeach, count);
        }

        return minUsersToTeach;
    }
};
