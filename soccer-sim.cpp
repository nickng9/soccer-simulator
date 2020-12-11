
#include <iostream>
#include <ctime>

using namespace std;
// initializing functions to be used with parameters
void event_generator(int num_events, int event_type, int shot_goes_in, int card_rand, int team_a_goals, int team_b_goals, int team_a_shots_on_g, int team_b_shots_on_g, int team_a_shots_off_g, int team_b_shots_off_g, int team_a_shots_blocked, int team_b_shots_blocked, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards);

void final_score_outputter (int shot_goes_in, int card_rand, int team_a_goals, int team_b_goals, int team_a_shots_on_g, int team_b_shots_on_g, int team_a_shots_off_g, int team_b_shots_off_g, int team_a_shots_blocked, int team_b_shots_blocked, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards);

void start_num_generator() { // generates the number of events for the game
    // initializing variables
    int num_events = 0;
    int event_type = 0;

    int shot_goes_in = 0;
    int card_rand = 0;

    int team_a_goals = 0;
    int team_b_goals = 0;

    int team_a_shots_on_g = 0;
    int team_b_shots_on_g = 0;

    int team_a_shots_off_g = 0;
    int team_b_shots_off_g = 0;

    int team_a_shots_blocked = 0;
    int team_b_shots_blocked = 0;

    int team_a_yellow_cards = 0;
    int team_b_yellow_cards = 0;

    int team_a_red_cards = 0;
    int team_b_red_cards = 0;
    
    srand(time(0)); // set srand seed to be time(0)
    num_events = rand() % 20 + 1;// generating a random number from 1 - 20
    // cout << num_events << endl;
    
    // calls event generator with set parameters
    event_generator(num_events, event_type, shot_goes_in, card_rand, team_a_goals, team_b_goals, team_a_shots_on_g, team_b_shots_on_g, team_a_shots_off_g, team_b_shots_off_g, team_a_shots_blocked, team_b_shots_blocked, team_a_yellow_cards, team_b_yellow_cards, team_a_red_cards, team_b_red_cards);
}

// event generator function
void event_generator(int num_events, int event_type, int shot_goes_in, int card_rand, int team_a_goals, int team_b_goals, int team_a_shots_on_g, int team_b_shots_on_g, int team_a_shots_off_g, int team_b_shots_off_g, int team_a_shots_blocked, int team_b_shots_blocked, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards) { // function for processing and output results of events
    for (int iterator_num = 0; iterator_num < num_events / 2; iterator_num++) { // for loop iterating over the number of events
        int event_type = rand() % 6 + 1; // randomly generated event numbers
        // cout << event_type << endl; // for testing purposes
        
        switch (event_type) { // switches the program depending on what the event_type number is (from rand)
            case 1: // event type = 1; involves A getting a shot off;
                // cout << "Team A shot on target" << endl << endl; // purely for testing purposes
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) { // first situation for case 1, shot goes in
                    team_a_goals++; // adds to the team a goals counter
                    team_a_shots_on_g++;
                    cout << "Team A has scored a goal! Fantastic shot!" << endl << endl; // output
                }
                else if (shot_goes_in == 1) { // 2nd situation for case 1, shot is on goal but blocked
                    team_a_shots_on_g++;
                    team_a_shots_blocked++;
                    cout << "Team B with a huge block! Insane effort from the defenders and keeper!" << endl << endl; // output
                }
                else if (shot_goes_in == 2){ // 3rd situation for case 1, shot is off goal, not blocked
                    team_a_shots_off_g++;
                    cout << "Team A missed wide! What a passed up opportunity!" << endl << endl; // output
                }
                else { // last situation for case 1, shot is off goal and blocked by someone not last defender / keeper
                    team_a_shots_off_g++;
                    team_a_shots_blocked++;
                    cout << "Team B with a huge defensive stop!" << endl << endl; // output
                }
                break;
                
            case 2: // event_type = 2; involves B getting a shot off
                // cout << "Team B shot on target" << endl << endl; // purely for testing purposes
        
                shot_goes_in = rand() % 3; // randomizer determining if shot goes in
                if (shot_goes_in == 0) {
                    team_b_goals++;
                    team_b_shots_on_g++;
                    cout << "Team B has scored a goal! Fantastic shot!" << endl << endl; // output
                }
                else if (shot_goes_in == 1) {
                    team_b_shots_on_g++;
                    team_b_shots_blocked++;
                    cout << "Team A with a huge block! Insane effort from the defenders and keeper!" << endl << endl; // output
                }
                else if (shot_goes_in == 2){
                    team_b_shots_off_g++;
                    cout << "Team B missed wide! What a passed up opportunity!" << endl << endl; // output
                }
                else{
                    team_b_shots_off_g++;
                    team_b_shots_blocked++;
                    cout << "Team A with a huge defensive stop!" << endl << endl; // output
                }
                break; // break statement b/w switches
                
            case 3: // situation where event_type = 3; B fouls and A gets a free kick
                // cout << "Team B fouls, A gets a free kick" << endl << endl; // purely for testing purposes
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) {
                    team_a_goals++;
                    team_a_shots_on_g++;
                    cout << "Team A has scored a goal! Fantastic shot!" << endl << endl; // output
                }
                else if (shot_goes_in == 1) {
                    team_a_shots_on_g++;
                    team_a_shots_blocked++;
                    cout << "Team B's keeper with an inhuman dive! What a save!" << endl << endl; // output
                }
                else if (shot_goes_in == 2) {
                    team_a_shots_off_g++;
                    cout << "Team A shoots wide! Tragic moment for their fans" << endl << endl; // output
                }
                else {
                    team_a_shots_off_g++;
                    team_a_shots_blocked++;
                    cout << "Team B with a huge defensive effort! Insane block by the defenders!" << endl << endl; // output
                }
                // randomizer for determining if a card is given out following the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_b_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_b_red_cards++;
                }
                break;
                
            case 4: // situation where event_type = 4; A fouls and B gets a free kick
               // cout << "Team A fouls, B gets a free kick" << endl << endl; // purely for testing
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) {
                    team_b_goals++;
                    team_b_shots_on_g++;
                    cout << "Team B has scored a goal! Fantastic shot!" << endl << endl; // output
                }
                else if (shot_goes_in == 1) {
                    team_b_shots_on_g++;
                    team_b_shots_blocked++;
                    cout << "Team A's keeper with an inhuman dive! What a save!" << endl << endl; // output
                }
                else if (shot_goes_in == 2) {
                    team_b_shots_off_g++;
                    cout << "Team B shoots wide! Tragic moment for their fans" << endl << endl; // output
                }
                else {
                    team_b_shots_off_g++;
                    team_b_shots_blocked++;
                    cout << "Team A with a huge defensive effort! Insane block by the defenders!" << endl << endl; // output
                }
                
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_a_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_a_red_cards++;
                }
                break;
                
            case 5: // situation where event_type = 5; B fouls near the box and A gets a penalty kick
               // cout << "Team B fouls, A gets a penalty kick" << endl << endl; // purely for testing
                shot_goes_in = rand() % 2;
                if (shot_goes_in == 0) { // shot goes in
                    team_a_goals++;
                    team_a_shots_on_g++;
                    cout << "Team A scores! Beautiful shot!" << endl << endl; // output
                }
                else if (shot_goes_in == 1) {
                    team_a_shots_on_g++;
                    team_a_shots_blocked++;
                    cout << "Team B's keeper with an inhuman dive! What a save!" << endl << endl; // output
                }
                else if (shot_goes_in == 2) {
                    team_a_shots_off_g++;
                    cout << "Team A shoots wide! Tragic moment for their fans" << endl << endl; // output
                }
                
                // card randomizer in terms of what card will be dealt after the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_b_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_b_red_cards++;
                }
                break;
                
                
            case 6: // situation where event_type = 6; A fouls near the box and B gets a penalty kick
                cout << "Team A fouls, B gets a penalty kick" << endl << endl; // purely for testing purposes
                shot_goes_in = rand() % 2;
                if (shot_goes_in == 0) {
                    team_b_goals++;
                    team_b_shots_on_g++;
                    cout << "Team B has scored a goal! Fantastic shot!" << endl << endl; // output
                }
                else if (shot_goes_in == 1) {
                    team_b_shots_on_g++;
                    team_b_shots_blocked++;
                    cout << "Team A's keeper with an inhuman dive! What a save!" << endl << endl; // output
                }
                else if (shot_goes_in == 2) {
                    team_b_shots_off_g++;
                    cout << "Team B shoots wide! Tragic moment for their fans" << endl << endl; // output
                }
                
                // card randomizer in terms of what card will be dealt after the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_a_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_a_red_cards++;
                }
                break;
        }
    }
    
    // half time stats, derived from the for loop that iterated to the number of events divided by 2
    cout << "HALFTIME STATS: " << endl << endl;
    cout << "Team A has " << team_a_goals << " goals, " << team_a_shots_on_g << " shots on goal, " << team_a_shots_off_g << " shots off goal, " << team_a_shots_blocked << " shots blocked, " << team_a_yellow_cards << " yellow cards and " << team_a_red_cards << " red cards." << endl << endl;
    
    cout << "Team B has " << team_b_goals << " goals, " << team_b_shots_on_g << " shots on goal, " << team_b_shots_off_g << " shots off goal, " << team_b_shots_blocked << " shots blocked, " << team_b_yellow_cards << " yellow cards and " << team_b_red_cards << " red cards." << endl << endl;

    for (int iterator_num2 = num_events / 2; iterator_num2 < num_events; iterator_num2++) { // for loop iterating over the number of events, starting from second half to the end
        int event_type = rand() % 6 + 1; // randomly generated event numbers
        // cout << event_type << endl; // for testing purposes
        
        switch (event_type) { // switches the program depending on what the event_type number is (from rand)
            case 1: // event type = 1; involves A getting a shot off;
               // cout << "Team A shot on target" << endl << endl; // purely for testing purposes
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) { // first situation for case 1, shot goes in
                    team_a_goals++;
                    team_a_shots_on_g++;
                    cout << "Team A has scored a goal! Fantastic shot!" << endl << endl;
                }
                else if (shot_goes_in == 1) { // 2nd situation for case 1, shot is on goal but blocked
                    team_a_shots_on_g++;
                    team_a_shots_blocked++;
                    cout << "Team B with a huge block! Insane effort from the defenders and keeper!" << endl << endl;
                }
                else if (shot_goes_in == 2){ // 3rd situation for case 1, shot is off goal, not blocked
                    team_a_shots_off_g++;
                    cout << "Team A missed wide! What a passed up opportunity!" << endl << endl;
                }
                else { // last situation for case 1, shot is off goal and blocked by someone not last defender / keeper
                    team_a_shots_off_g++;
                    team_a_shots_blocked++;
                    cout << "Team B with a huge defensive stop!" << endl << endl;
                }
                break;
                
            case 2: // event_type = 2; involves B getting a shot off
               // cout << "Team B shot on target" << endl << endl; // purely for testing purposes
        
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) {
                    team_b_goals++;
                    team_b_shots_on_g++;
                    cout << "Team B has scored a goal! Fantastic shot!" << endl << endl;
                }
                else if (shot_goes_in == 1) {
                    team_b_shots_on_g++;
                    team_b_shots_blocked++;
                    cout << "Team A with a huge block! Insane effort from the defenders and keeper!" << endl << endl;
                }
                else if (shot_goes_in == 2){
                    team_b_shots_off_g++;
                    cout << "Team B missed wide! What a passed up opportunity!" << endl << endl;
                }
                else{
                    team_b_shots_off_g++;
                    team_b_shots_blocked++;
                    cout << "Team A with a huge defensive stop!" << endl << endl;
                }
                break;
                
            case 3: // situation where event_type = 3; B fouls and A gets a free kick
               // cout << "Team B fouls, A gets a free kick" << endl << endl; // purely for testing purposes
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) {
                    team_a_goals++;
                    team_a_shots_on_g++;
                    cout << "Team A has scored a goal! Fantastic shot!" << endl << endl;
                }
                else if (shot_goes_in == 1) {
                    team_a_shots_on_g++;
                    team_a_shots_blocked++;
                    cout << "Team B's keeper with an inhuman dive! What a save!" << endl << endl;
                }
                else if (shot_goes_in == 2) {
                    team_a_shots_off_g++;
                    cout << "Team A shoots wide! Tragic moment for their fans" << endl << endl;
                }
                else {
                    team_a_shots_off_g++;
                    team_a_shots_blocked++;
                    cout << "Team B with a huge defensive effort! Insane block by the defenders!" << endl << endl;
                }
                
                // card randomizer in terms of what card will be dealt after the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_b_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_b_red_cards++;
                }
                break;
                
            case 4: // situation where event_type = 4; A fouls and B gets a free kick
              //  cout << "Team A fouls, B gets a free kick" << endl << endl; // purely for testing
                shot_goes_in = rand() % 3;
                if (shot_goes_in == 0) {
                    team_b_goals++;
                    team_b_shots_on_g++;
                    cout << "Team B has scored a goal! Fantastic shot!" << endl << endl;
                }
                else if (shot_goes_in == 1) {
                    team_b_shots_on_g++;
                    team_b_shots_blocked++;
                    cout << "Team A's keeper with an inhuman dive! What a save!" << endl << endl;
                }
                else if (shot_goes_in == 2) {
                    team_b_shots_off_g++;
                    cout << "Team B shoots wide! Tragic moment for their fans" << endl << endl;
                }
                else {
                    team_b_shots_off_g++;
                    team_b_shots_blocked++;
                    cout << "Team A with a huge defensive effort! Insane block by the defenders!" << endl << endl;
                }
                
                // card randomizer in terms of what card will be dealt after the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_a_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_a_red_cards++;
                }
                break;
                
            case 5: // situation where event_type = 5; B fouls near the box and A gets a penalty kick
               // cout << "Team B fouls, A gets a penalty kick" << endl << endl; // purely for testing
                shot_goes_in = rand() % 2;
                if (shot_goes_in == 0) { // shot goes in
                    team_a_goals++;
                    team_a_shots_on_g++;
                    cout << "Team A scores! Beautiful shot!" << endl << endl;
                }
                else if (shot_goes_in == 1) {
                    team_a_shots_on_g++;
                    team_a_shots_blocked++;
                    cout << "Team B's keeper with an inhuman dive! What a save!" << endl << endl;
                }
                else if (shot_goes_in == 2) {
                    team_a_shots_off_g++;
                    cout << "Team A shoots wide! Tragic moment for their fans" << endl << endl;
                }
                
                // card randomizer in terms of what card will be dealt after the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_b_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_b_red_cards++;
                }
                break;
                
                
            case 6: // situation where event_type = 6; A fouls near the box and B gets a penalty kick
               // cout << "Team A fouls, B gets a penalty kick" << endl << endl; // purely for testing purposes
                shot_goes_in = rand() % 2;
                if (shot_goes_in == 0) {
                    team_b_goals++;
                    team_b_shots_on_g++;
                    cout << "Team B has scored a goal! Fantastic shot!" << endl << endl;
                }
                else if (shot_goes_in == 1) {
                    team_b_shots_on_g++;
                    team_b_shots_blocked++;
                    cout << "Team A's keeper with an inhuman dive! What a save!" << endl << endl;
                }
                else if (shot_goes_in == 2) {
                    team_b_shots_off_g++;
                    cout << "Team B shoots wide! Tragic moment for their fans" << endl << endl;
                }
                
                // card randomizer in terms of what card will be dealt after the foul
                card_rand = rand() % 2;
                if (card_rand == 1) {
                    team_a_yellow_cards++;
                }
                else if (card_rand == 2) {
                    team_a_red_cards++;
                }
                break;
        }
    }
    final_score_outputter(shot_goes_in, card_rand, team_a_goals, team_b_goals, team_a_shots_on_g, team_b_shots_on_g, team_a_shots_off_g, team_b_shots_off_g, team_a_shots_blocked, team_b_shots_blocked, team_a_yellow_cards, team_b_yellow_cards, team_a_red_cards, team_b_red_cards);
}

// Final score and stats outputter
void final_score_outputter (int shot_goes_in, int card_rand, int team_a_goals, int team_b_goals, int team_a_shots_on_g, int team_b_shots_on_g, int team_a_shots_off_g, int team_b_shots_off_g, int team_a_shots_blocked, int team_b_shots_blocked, int team_a_yellow_cards, int team_b_yellow_cards, int team_a_red_cards, int team_b_red_cards) {
    cout << "Final Stats: " << endl << endl;
    cout << "Team A has " << team_a_goals << " goals, " << team_a_shots_on_g << " shots on goal, " << team_a_shots_off_g << " shots off goal, " << team_a_shots_blocked << " shots blocked, " << team_a_yellow_cards << " yellow cards and " << team_a_red_cards << " red cards." << endl << endl;
    
    cout << "Team B has " << team_b_goals << " goals, " << team_b_shots_on_g << " shots on goal, " << team_b_shots_off_g << " shots off goal, " << team_b_shots_blocked << " shots blocked, " << team_b_yellow_cards << " yellow cards and " << team_b_red_cards << " red cards." << endl << endl;
    
    cout << "The final score is: " << team_a_goals << " : " << team_b_goals << endl; // specifically the final score
}

// calls function:
int main() {
    start_num_generator();
}