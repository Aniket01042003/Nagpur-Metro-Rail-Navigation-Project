#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

void createmap(vector<string> &station_list)
{
    station_list.push_back("start2");
    station_list.push_back("Lokmanya_Nagar");
    station_list.push_back("Bansi_Nagar");
    station_list.push_back("Vasudev_Nagar");
    station_list.push_back("Rachana_Ring");
    station_list.push_back("Shubhash_Nagar");
    station_list.push_back("Dharam_Peth");
    station_list.push_back("LAD_Square");
    station_list.push_back("Shankar_Nagar");
    station_list.push_back("NIT");
    station_list.push_back("Jhansi_Rani_Square");
    station_list.push_back("Sita_Buldi junction");
    station_list.push_back("Cotton_Market");
    station_list.push_back("Nagpur_In");
    station_list.push_back("Dosar_Vaiashya_Sq");
    station_list.push_back("Agressan_Sq");
    station_list.push_back("Chitroli_Sq");
    station_list.push_back("Telephone_Exchange");
    station_list.push_back("Ambedkar_Sq");
    station_list.push_back("Vaishnodevi");
    station_list.push_back("Prajapati_Sq");
    station_list.push_back("end");
    station_list.push_back("start2");
    station_list.push_back("Khapri");
    station_list.push_back("New Airport");
    station_list.push_back("Airport South");
    station_list.push_back("Airport");
    station_list.push_back("Ujjwal Nagar");
    station_list.push_back("Jaiprakash Nagar");
    station_list.push_back("Chhatrapati Square");
    station_list.push_back("Ajni Square");
    station_list.push_back("Rahate Colony");
    station_list.push_back("Congress Nagar");
    station_list.push_back("Zero Mile");
    station_list.push_back("Kasturchand Park");
    station_list.push_back("Gaddi Godam Square");
    station_list.push_back("Kadbi Chowk");
    station_list.push_back("Indora Square");
    station_list.push_back("Nari Road");
    station_list.push_back("Automotive Square");
    station_list.push_back("end2");
    
}
void showmap(vector<string> &station)
{
    int j = 1;
    for (int i = 1; i < station.size() - 1; i++)
    {
        cout << i << " " << station[i] << endl;
    }
}

void createadjlist(vector<vector<int>> &adj)
{
    adj[1] = {2};
    adj[2] = {1, 3};
    adj[3] = {2, 4};
    adj[4] = {3, 5};
    adj[5] = {4, 6};
    adj[6] = {5, 7};
    adj[7] = {6, 8};
    adj[8] = {7, 9};
    adj[9] = {8, 10};
    adj[10] = {9, 11};
    adj[11] = {10, 12,32,33};
    adj[12] = {11, 13};
    adj[13] = {12, 14};
    adj[14] = {13, 15};
    adj[15] = {14, 16};
    adj[16] = {15, 17};
    adj[17] = {16, 18};
    adj[18] = {17, 19};
    adj[19] = {18, 20};
    adj[20] = {19};
    adj[21] = {20};
    adj[22] = {23};
    adj[23] = {24};
    adj[24] = {23, 25};
    adj[25] = {24, 26};
    adj[26] = {25, 27};
    adj[27] = {26, 28};
    adj[28] = {27, 29};
    adj[29] = {28, 30};
    adj[30] = {29, 31};
    adj[31] = {30, 32};
    adj[32] = {31, 11};
    adj[33] = {11, 34};
    adj[34] = {33, 35};
    adj[35] = {34, 36};
    adj[36] = {35, 37};
    adj[37] = {36, 38};
    adj[38] = {37, 39};
    adj[39] = {38};
}
void showMetroMap(vector<string> &station_list, vector<vector<int>> &adj)
{
    for (int i = 1; i < adj.size(); i++)
    {
        cout << i << " " << station_list[i] << "==>" << endl;
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << "   " << station_list[adj[i][j]] << endl;
        }
        cout << endl;
    }
}

vector<int> shortestPath(int src, int dest, vector<vector<int>> &adj)
{
    vector<bool> visited(41, false);
    vector<int> parent(41, -1);
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    visited[src] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto ele : adj[front])
        {
            if (visited[ele] == false)
            {
                visited[ele] = true;
                parent[ele] = front;
                q.push(ele);
            }
        }
    }
    vector<int> ans;
    int currnode = dest;
    ans.push_back(dest);

    while (currnode != src)
    {
        currnode = parent[currnode];
        ans.push_back(currnode);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
double showdistance(vector<int> path, vector<double> &dist)
{
    double dit = 0;
    for (auto i : path)
    {
        dit += dist[i];
    }
    return dit;
}
int showtime(vector<int> path, vector<int> &time)
{
    int tt = 0;
    for (auto i : path)
    {
        tt += time[i];
    }
    return tt;
}

int main()
{
    vector<vector<int>> adj(41, vector<int>(2));
    vector<double> dist = {0, 0, 1.3, 0.8, 1.1, 1.4, 0.8, 1.3, 0.8, 0.9, 1.1, 0.35, 0.9, 0.7, 0.8, 0.8, 0.85, 0.8, 1.2, 1, 1.4, 0,0, 0, 1.3, 0.8, 1.1, 1.4, 0.8, 1.3, 0.8, 0.9, 1.1, 0.35, 0.9, 0.7, 0.8, 0.8, 0.85, 0.8, 1.2, 1, 1.4, 0,};
    vector<int> time = {0, 0, 3, 3, 3, 4, 2, 4, 2, 3, 3, 1, 3, 2, 2, 2, 3, 2, 4, 2, 3, 0,0, 0, 3, 3, 3, 4, 2, 4, 2, 3, 3, 1, 3, 2, 2, 2, 3, 2, 4, 2, 3, 0};
    vector<string> station;
    createmap(station);
    createadjlist(adj);
    bool flag = true;
    while (flag)
    {
        cout << "\n\t\t\t****WELCOME TO THE METRO APP Nagpur Aqua Line*****" << endl;
        cout << "\t\t\t\t~~LIST OF ACTIONS~~\n\n";
        cout << "1. LIST ALL THE STATIONS IN THE MAP" << endl;
        cout << "2. SHOW THE METRO MAP" << endl;
        cout << "3. GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "4. GET SHORTEST TIME TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "5. GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "6. GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
        cout << "7. EXIT THE MENU" << endl;
        cout << "ENTER YOUR CHOICE FROM THE ABOVE LIST (1 to 7) : " << endl;
        int choice = -1;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            cout << "******************LIST ALL THE STATIONS IN THE MAP****************" << endl;
            showmap(station);
            break;
        }
        case 2:
        {
            cout << "******************SHOW THE METRO MAP******************" << endl;
            showMetroMap(station, adj);
            break;
        }
        case 3:
        {
            cout << "GET SHORTEST DISTANCE FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
            showmap(station);
            cout << "Enter Station Starting Code from above map" << endl;
            int s, d;
            cin >> s;
            cin >> d;
            vector<int> p;
            p = shortestPath(s, d, adj);
            double dis = showdistance(p, dist);
            cout << "minimum distance between " << station[s] << " and " << station[d] << " is " << dis << " km" << endl;
            break;
        }
        case 4:
        {
            cout << "GET SHORTEST TIME TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
            showmap(station);
            cout << "Enter Station Starting Code from above map" << endl;
            int s, d;
            cin >> s;
            cin >> d;
            vector<int> p;
            p = shortestPath(s, d, adj);
            int tt = showtime(p, time);
            cout << "minimum time between " << station[s] << " and " << station[d] << " is " << tt << " minutes" << endl;
            break;
        }
        case 5:
        {
            cout << "GET SHORTEST PATH (DISTANCE WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
            showmap(station);
            cout << "Enter Station Starting Code from above map" << endl;
            int s, d;
            cin >> s;
            cin >> d;
            vector<int> p;
            p = shortestPath(s, d, adj);
            cout << "Shortest Path is " << endl;
            double d2 = 0;
            for (auto ele : p)
            {
                d2 += dist[ele];
                cout << station[ele] << " '" << d2 << "km'";
                if (ele != p.back())
                    cout << " => ";
            }
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "GET SHORTEST PATH (TIME WISE) TO REACH FROM A 'SOURCE' STATION TO 'DESTINATION' STATION" << endl;
            showmap(station);
            cout << "Enter Station Starting Code from above map" << endl;
            int s, d;
            cin >> s;
            cin >> d;
            vector<int> p;
            p = shortestPath(s, d, adj);
            cout << "Shortest Path is " << endl;
            int t2 = 0;
            for (auto ele : p)
            {
                t2 += time[ele];
                cout << station[ele] << " '" << t2 << "min'";
                if (ele != p.back())
                    cout << " => ";
            }
            cout << endl;
            break;
        }
        case 7:
        {
            cout << "EXIT" << endl;
            flag = false;
            break;
        }
        default:
        {
            cout << "Error Occur !!!!!!!!" << endl;
            cout << "invalid input" << endl;
            cout << "Please re-enter the input" << endl;
            break;
        }
        }
    }
    cout << "THANKS FOR USING OUR APPLICATION" << endl;
    return 0;
}