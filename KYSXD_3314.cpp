//"""
//#KYSXD - Problema 3314
//Fast Traveler Game
//"""

#include <iostream>
#include <string>
#include <algorithm>

#include <sstream>

template <typename T>
std::string to_string(T value)
{
    std::ostringstream os ;
    os << value ;
    return os.str() ;
}

using namespace std;

int update(int winner[][1], int num, int position, int size) {
	return (position == size-1 ? 1 : 0);
}

int next(int current, int lim, int winner[][1]){
    if(winner[(current + 1)%lim][0] == 0) {
        return (current + 1)%lim;
    }
    else return next((current + 1)%lim, lim, winner);
}

int main()
{
    int n_games, n_players, g_size, n_turns;
    cin >> n_games;


    for (int k = 0; k < n_games; k++) {
        cin >> n_players >> g_size >> n_turns;

        string print_winners = "-1";

        int player[n_players][1]; //Jugador, posicion
        int winner[n_players][1]; //Jugador, estado
        int board[g_size]; //Cada casilla del tablero
        int turns[n_turns]; //Movimiento en cada turno

        for(int i = 0; i < n_players; i++) {
            winner[i][0] = 0;
        	player[i][0] = 0;
        }

        for(int i = 0; i < g_size; i++) {
        	cin >> board[i];
        }

        for(int i = 0;  i < n_turns; i++) {
        	cin >> turns[i];
        }

        int current_player = 0;
        int thelast_winner = -1;
        for(int i = 0; i < n_turns; i++) {
            player[current_player][0] += turns[i];
            player[current_player][0] += board[player[current_player][0]];
            winner[current_player][0] = update(winner, current_player, player[current_player][0], g_size);
            if (winner[current_player][0] == 1) {
                ++thelast_winner;
                if (thelast_winner == 0) {
                    print_winners = to_string(current_player + 1);
                }
                else print_winners += " " + to_string(current_player + 1);
            }
            if (i != n_turns - 1) {
                current_player = next(current_player, n_players, winner);
            }
        }
        cout << print_winners << endl;
    }

    return 0;
}