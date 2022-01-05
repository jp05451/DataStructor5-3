#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

class luckyBlock
{
public:
    int first;
    int second;
    //bool usable = 0;
};

class MatchMaker
{
public:
    MatchMaker(int);

    int luckyFinder(int);
    int binarySearch(int);
    void inputPeople();
    void inputLuckyNumber();
    void outputMatch(int);
    void buildHashTable();

    vector<int> luckyNumber;
    vector<int> NumberOfPerson;
    map<int, vector<luckyBlock>> hashTable;
};

MatchMaker::MatchMaker(int size)
{
    NumberOfPerson.resize(size);
}

void MatchMaker::inputPeople()
{
    for (int i = 0; i < NumberOfPerson.size(); i++)
    {
        cin >> NumberOfPerson[i];
    }
}

int MatchMaker::binarySearch(int target)
{
    int begin = 0;
    int end = luckyNumber.size() - 1;
    int cursor = begin - end;
    while (begin <= end)
    {
        if (target == luckyNumber[cursor])
        {
            return cursor;
        }
        if (target > luckyNumber[cursor])
        {
            begin = cursor + 1;
        }
        else
        {
            end = cursor - 1;
        }
        cursor = (begin + end) / 2;
    }
    return -1;
}

int MatchMaker::luckyFinder(int target)
{
    vector<int>::iterator it = find(luckyNumber.begin(), luckyNumber.end(), target);
    if (it == luckyNumber.end())
    {
        return -1;
    }
    return distance(luckyNumber.begin(), it);
}

void MatchMaker::inputLuckyNumber()
{
    int temp;
    while (cin >> temp)
    {
        luckyNumber.push_back(temp);
    }
}

void MatchMaker::outputMatch(int target)
{
    // for (int i = 0; i < NumberOfPerson.size() - 1; i++)
    // {
    //     for (int j = i + 1; j < NumberOfPerson.size(); j++)
    //     {
    //         if (NumberOfPerson[i] + NumberOfPerson[j] == target)
    //         {
    //             cout << NumberOfPerson[i] << " " << NumberOfPerson[j] << endl;
    //         }
    //     }
    // }
    if (!hashTable[target].empty())
    {
        for (auto &p : hashTable[target])
        {
            cout << p.first << " " << p.second << endl;
        }
    }
}

void MatchMaker::buildHashTable()
{
    for (int i = 0; i < NumberOfPerson.size() - 1; i++)
    {
        for (int j = i + 1; j < NumberOfPerson.size(); j++)
        {
            luckyBlock L;
            L.first = NumberOfPerson[i];
            L.second = NumberOfPerson[j];
            int sum = L.first + L.second;
            hashTable[sum].push_back(L);
        }
    }
}

//********************main**************
int main()
{
    int size;
    cin >> size;

   
    MatchMaker M(size);
    M.inputPeople();
    M.inputLuckyNumber();
    M.buildHashTable();
    for (int i = 0; i < M.luckyNumber.size(); i++)
    {
        M.outputMatch(M.luckyNumber[i]);
    }
}