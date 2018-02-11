#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 




bool compare(Player p1, Player p2)
{
    int diff = 0;
    if(p1.score==p2.score)
        diff = p2.name.compare(p1.name);
    else
        diff = p1.score - p2.score;
    
    if(diff>0)
        return true;
    
    return false;
}

int doIt(vector<Player> &players, int left, int right)
{
    int pivot=(right+left)/2;
    Player val=players[pivot];
    
    while(left<=right)
    {
        while(compare(players[left], val))
        {
            left++;
        }
        
        while(compare(val, players[right]))
        {
            right--;
        }
        
        if(left<=right)
        {
            //cout << "Swapping " << left << " with " << right << endl;
            Player temp = players[right];
            players[right] = players[left];
            players[left] = temp;
            left++;
            right--;
        }
        
        
    }
    
    return left;
}

void quickSort(vector<Player> &players, int left, int right)
{
    if(left>=right)
        return;
    
    //cout << "On " << left << " with " << right << endl;
    
    int next=doIt(players, left, right);
    //cout << "returned " << next << endl;
    quickSort(players, left, next-1);
    quickSort(players, next, right);
}


vector<Player> comparator(vector<Player> players) {
    
    quickSort(players, 0, players.size()-1);
    
    return players;

}




int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}

