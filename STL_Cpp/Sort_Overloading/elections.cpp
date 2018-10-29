#include<iostream>
#include<map>
#include<string>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<string, int> myPair;

map <string, int> voteBallot;
vector <myPair> ballot2;

bool wayToSort (myPair P1, myPair P2)
{
    if (P1.second > P2.second)
    {
        return true;
    }
    else if (P1.second < P2.second)
    {
        return false;
    }
    return P1.first < P2.first ;
}

void getInput (int& numVoters)
{
    cout << "Enter the number of voters :  ";
    cin >> numVoters;

    cout << "Enter your votes (candidate names you want to vote) one by one :    " << endl;

    for (int i = 0; i < numVoters; i ++)
    {
        string temp;
        cin >> temp;
        voteBallot [temp] ++;
    }
}

void printElectionStatus ()
{
    cout << "The current status of elections : " << endl;
    map <string, int> :: iterator itr;
    for (itr = voteBallot.begin (); itr != voteBallot.end (); itr ++)
    {
        cout << itr -> first << "--------" << itr -> second << endl;
    }
}

//This function will sort map first by num of votes and then alphabetically.
void manualSort ()
{
    map <string, int> ::iterator itr;

    for (itr = voteBallot.begin (); itr != voteBallot.end (); itr ++)
    {
        myPair P1 = *itr;
        ballot2.push_back (P1);
    }

    sort (ballot2.begin (), ballot2.end (), wayToSort);

}

void printElectionStatus2 ()
{
    cout << "The current status of elections : " << endl;
    vector <myPair> :: iterator itr;
    for (itr = ballot2.begin (); itr != ballot2.end (); itr ++)
    {
        cout << itr -> first << "--------" << itr -> second << endl;
    }
}

int main()
{
    int numVoters;

    getInput (numVoters);

    printElectionStatus ();

    manualSort (); 

    printElectionStatus2 ();

    return 0;
}