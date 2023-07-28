#include <bits/stdc++.h>
using namespace std;

// function to print all the permutation with spaces of a string
/*Example:
String: ABC
Output: ABC A_BC AB_C A_B_C
*/
void permutationWithSpaces(string str, string ans)
{
    // base condition
    if (str.size() == 1)
    {
        ans.push_back(str[0]);
        cout << ans << endl;
        return;
    }
    ans.push_back(str[0]);
    str.erase(str.begin() + 0);

    // include space
    ans.push_back('_');
    permutationWithSpaces(str, ans);

    // backtracking
    ans.pop_back();

    // not including space
    permutationWithSpaces(str, ans);
}

// function to print permutations of a string with case change
/*Assumption:string must be in lowercase and string contains only lowercase letters
Example:
String = ab
Output: ab Ab aB AB*/

void permutationWithCaseChange(string str, string ans)
{

    // Base condition
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }
    char temp = str[0];
    str.erase(str.begin() + 0); // making input smaller

    // here we have two choices, either use small case or capital case

    // lower case
    ans.push_back(temp);
    permutationWithCaseChange(str, ans);

    // backtracking
    ans.pop_back();

    // upper case
    ans.push_back(toupper(temp));
    permutationWithCaseChange(str, ans);
}

// function to print letter case permutation of a string
/*Assumption: including digits, uppercase letters, lowercase letters
Example: a1B2
Output: a1B2 A1B2 a1b2 A1b2*/

void letterCasePermutation(string str, string ans)
{

    // base condition
    if (str.size() == 0)
    {
        cout << ans << endl;
        return;
    }

    if (int(str[0]) >= 48 && int(str[0]) <= 57)
    { // if character is a number
        ans.push_back(str[0]);
        str.erase(str.begin() + 0);
        letterCasePermutation(str, ans);
    }
    else
    { // if character is an alphabet
        char temp = str[0];
        str.erase(str.begin() + 0); // making input smaller

        // here we have two choices, either include lowercase or uppercase

        // LowerCase
        ans.push_back(tolower(temp));
        letterCasePermutation(str, ans);

        // backtracking
        ans.pop_back();

        // UpperCase
        ans.push_back(toupper(temp));
        letterCasePermutation(str, ans);
    }
}

// Driver Code
int main()
{
    cout << "Enter a string:" << endl;
    string str;
    cin >> str;

    string ans = "";

    // cout<<"Permutations with space"<<endl;
    // permutationWithSpaces(str,ans);

    // cout<<"Permutations with case change"<<endl;
    // permutationWithCaseChange(str,ans);

    cout << "Letter Case Permutations" << endl;
    letterCasePermutation(str, ans);

    return 0;
}