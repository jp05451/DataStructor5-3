#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

class MatchMaker
{
public:
    MatchMaker(int);

    int luckyFinder(int);
    int binarySearch(int, const vector<int> &);
    void inputPeople();
    void inputLuckyNumber();
    void outputMatch();
    void buildHashTable();
    void openFile();

    vector<int> luckyNumber;
    vector<int> NumberOfPerson;
};

MatchMaker::MatchMaker(int size)
{
    // inputFile.open("testCase.txt", ios::in);

    // inputFile >> size;

    NumberOfPerson.resize(size);
}

void MatchMaker::inputPeople()
{
    for (int i = 0; i < NumberOfPerson.size(); i++)
    {
        cin >> NumberOfPerson[i];
    }
}

int MatchMaker::binarySearch(int target, const vector<int> &list)
{
    int begin = 0;
    int end = list.size() - 1;
    int cursor = begin - end;
    while (begin <= end)
    {
        if (target == list[cursor])
        {
            return cursor;
        }
        if (target > list[cursor])
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

void MatchMaker::inputLuckyNumber()
{
    int temp;
    while (cin >> temp)
    {
        luckyNumber.push_back(temp);
    }
}

void MatchMaker::outputMatch()
{
    unordered_map<int, int>::iterator it;
    unordered_map<int, int> outputList;
    for (auto &target : luckyNumber)
    {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < NumberOfPerson.size(); i++)
        {
            it = hashTable.find(target - NumberOfPerson[i]);
            if (it == hashTable.end())
            {
                hashTable[NumberOfPerson[i]] = i;
            }
            else
            {
                if (outputList.find(min(it->second, i)) == outputList.end())
                {
                    cout << NumberOfPerson[min(it->second, i)] << " " << NumberOfPerson[max(it->second, i)] << endl;
                    break;
                }
                else
                {
                    outputList[min(it->second, i)] = max(it->second, i);
                }
            }
        }
    }
}

//********************main**************
int main()
{
    int size = 1;
    cin >> size;

    MatchMaker M(size);
    M.inputPeople();
    M.inputLuckyNumber();

    M.outputMatch();
}
