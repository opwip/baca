// Yaroslav Kolesnik
#include <iostream>
using namespace std;

int main()
{
    char id, typea, lastid, lasttypea, who_won, who_lost;
    float laststr, str, awin, arem, alost, bwin, brem, blost, cwin, crem, clost, dwin, drem, dlost;
    awin = arem = alost = bwin = brem = blost = cwin = crem = clost = dwin = drem = dlost = 0;
    int n, lastn;
    cin >> n;
    bool are_players_ready, second_won, remis;
    while (n > 0)
    {
        cin >> id >> typea >> str;
        if (are_players_ready)
        {
            // cout << id << endl;
            // Simple win logic
            if (typea == 'J' && (lasttypea == 'P' || lasttypea == 'S'))
            {
                second_won = true;
            }
            else if (typea == 'K' && (lasttypea == 'J' || lasttypea == 'N'))
            {
                second_won = true;
            }
            else if (typea == 'N' && (lasttypea == 'P' || lasttypea == 'J'))
            {
                second_won = true;
            }
            else if (typea == 'S' && (lasttypea == 'K' || lasttypea == 'N'))
            {
                second_won = true;
            }
            else if (typea == 'P' && (lasttypea == 'K' || lasttypea == 'S'))
            {
                second_won = true;
            }
            // Ties logic
            if (typea == lasttypea)
            {
                // cout << str << ' ' << laststr << endl;
                if (str > laststr)
                {
                    second_won = true;
                }
                else if (laststr == str)
                {
                    remis = true;
                }
            }

            // Set the winner
            if (!second_won && !remis)
            {
                who_won = lastid;
                who_lost = id;
            }
            else if (!remis)
            {
                who_won = id;
                who_lost = lastid;
            }

            // Add to the stats
            if (!remis)
            {
                if (who_won == 'a')
                {
                    awin = awin + 1;
                }
                else if (who_won == 'b')
                {
                    bwin = bwin + 1;
                }
                else if (who_won == 'c')
                {
                    cwin = cwin + 1;
                }
                else if (who_won == 'd')
                {
                    dwin = dwin + 1;
                }

                if (who_lost == 'a')
                {
                    alost = alost + 1;
                }
                else if (who_lost == 'b')
                {
                    blost = blost + 1;
                }
                else if (who_lost == 'c')
                {
                    clost = clost + 1;
                }
                else if (who_lost == 'd')
                {
                    dlost = dlost + 1;
                }
            }
            else if (remis)
            {
                if (id == 'a')
                {
                    arem = arem + 1;
                }
                else if (id == 'b')
                {
                    brem = brem + 1;
                }
                else if (id == 'c')
                {
                    crem = crem + 1;
                }
                else if (id == 'd')
                {
                    drem = drem + 1;
                }

                if (lastid == 'a')
                {
                    arem = arem + 1;
                }
                else if (lastid == 'b')
                {
                    brem = brem + 1;
                }
                else if (lastid == 'c')
                {
                    crem = crem + 1;
                }
                else if (lastid == 'd')
                {
                    drem = drem + 1;
                }
            }

            // cout << who_won << endl;
            second_won = false;
            remis = false;
            are_players_ready = false;
            n = n - 1;
        }
        else
        {
            lastid = id;
            lasttypea = typea;
            laststr = str;
            are_players_ready = true;
        }
    }
    // cout << brem << ' ' << bwin + blost + brem << endl;
    if (awin + alost + arem > 0)
    {
        cout << "gracz a" << endl;
        if (awin != 0)
            cout << "    wygrane: " << awin / (awin + alost + arem) * 100 << '%' << endl;
        if (arem != 0)
            cout << "    remisy: " << arem / (awin + alost + arem) * 100 << '%' << endl;
        if (alost != 0)
            cout << "    przegrane: " << alost / (awin + alost + arem) * 100 << '%' << endl;
        cout << endl;
    }

    if (bwin + blost + brem > 0)
    {
        cout << "gracz b" << endl;
        if (bwin != 0)
            cout << "    wygrane: " << bwin / (bwin + blost + brem) * 100 << '%' << endl;
        if (brem != 0)
            cout << "    remisy: " << brem / (bwin + blost + brem) * 100 << '%' << endl;
        if (blost != 0)
            cout << "    przegrane: " << blost / (bwin + blost + brem) * 100 << '%' << endl;
        cout << endl;
    }

    if (cwin + clost + crem > 0)
    {
        cout << "gracz c" << endl;
        if (cwin != 0)
            cout << "    wygrane: " << cwin / (cwin + clost + crem) * 100 << '%' << endl;
        if (crem != 0)
            cout << "    remisy: " << crem / (cwin + clost + crem) * 100 << '%' << endl;
        if (clost != 0)
            cout << "    przegrane: " << clost / (cwin + clost + crem) * 100 << '%' << endl;
        cout << endl;
    }

    if (dwin + dlost + drem > 0)
    {
        cout << "gracz d" << endl;
        if (dwin != 0)
            cout << "    wygrane: " << dwin / (dwin + dlost + drem) * 100 << '%' << endl;
        if (drem != 0)
            cout << "    remisy: " << drem / (dwin + dlost + drem) * 100 << '%' << endl;
        if (dlost != 0)
            cout << "    przegrane: " << dlost / (dwin + dlost + drem) * 100 << '%' << endl;
        cout << endl;
    }

    return 0;
}