#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/* 

Project: Simulating a Soccer Game
Purpose: Write a program that simulates a game of soccer where two teams are
playing a single game: Team A and Team B.

Testing & Debugging Scenarios:
1. Manually counted the number of events that occur of each type for 3 complete trials
2. Created various specific pre-determined scenarios and determined if the code was able to produce the same output
3. Backtracked steps when an error arose, looking at where the code last worked and working through the new code from there
4. Tested individual sections of code in a separate file to determine errors and mistakes
*/

// Function to check and update cards for Team A
//      INPUTS: random_card_a (determines the card given for a foul committed by Team A), 
//      team_a_red_cards (number of red cards for Team A), team_a_yellow_cards (number of yellow cards for Team A)
//      RETURNS: Void, no returns
void card_check_a(int random_card_a, int &team_a_red_cards, int &team_a_yellow_cards);

// Function to check and update cards for Team B
//      INPUTS: random_card_b (determines the card given for a foul committed by Team B), 
//      team_b_red_cards (number of red cards for Team B), team_b_yellow_cards (number of yellow cards for Team B)
//      RETURNS: Void, no returns
void card_check_b(int random_card_b, int &team_b_red_cards, int &team_b_yellow_cards);

// Function to check and update goals for Team A
//      INPUTS: random_goal_a (determines the outcome of a shot by Team A), team_a_score (Team A's score), 
//      shots_on_target_by_a (number of shots on target by Team A), 
//      shots_off_target_by_a (number of shots off target by Team A), 
//      blocked_shots_a (number of shots taken by Team A that were blocked)
//      RETURNS: Void, no returns
void goal_check_a(int random_goal_a, int &team_a_score, int &shots_on_target_by_a, int &shots_off_target_by_a, int &blocked_shots_a);

// Function to check and update goals for Team B
//      INPUTS: random_goal_b (determines the outcome of a shot by Team B), team_b_score (Team B's score), 
//      shots_on_target_by_b (number of shots on target by Team B), 
//      shots_off_target_by_b (number of shots off target by Team B), 
//      blocked_shots_b (number of shots taken by Team B that were blocked)
//      RETURNS: Void, no returns
void goal_check_b(int random_goal_b, int &team_b_score, int &shots_on_target_by_b, int &shots_off_target_by_b, int &blocked_shots_b);

// Function to determine which of the 6 random possible event cases occurs for all 30 events
//      INPUTS: random (random event case), team_a_score, team_b_score, team_a_red_cards, team_a_yellow_cards, 
//      team_b_red_cards, team_b_yellow_cards, shots_on_target_by_a, shots_on_target_by_b, shots_off_target_by_a, 
//      shots_off_target_by_b, blocked_shots_a, blocked_shots_b, foul_a (fouls committed by Team A), 
//      foul_b (fouls committed by Team B)
//      RETURNS: Void, no returns
void event_cases(int random, int &team_a_score, int &team_b_score, int &team_a_red_cards, int &team_a_yellow_cards, int &team_b_red_cards, int &team_b_yellow_cards, int &shots_on_target_by_a, int &shots_on_target_by_b, int &shots_off_target_by_a, int &shots_off_target_by_b, int &blocked_shots_a, int &blocked_shots_b, int &foul_a, int &foul_b);

void card_check_a (int random_card_a, int &team_a_red_cards, int &team_a_yellow_cards) {
    // Check if no card is given
    if (random_card_a == 0)
        cout << "No card given to Team A" << endl;
    // Check if a yellow card is given
    else if (random_card_a == 1){
        cout << "A YELLOW card has been given to Team A" << endl;
        team_a_yellow_cards += 1;
    // Check if a red card is given
    } else if (random_card_a == 2) {
        cout << "A RED card has been given to Team A" << endl;
        team_a_red_cards += 1;
    }
}

void card_check_b  (int random_card_b, int &team_b_red_cards, int &team_b_yellow_cards) {
    // Check if no card is given
    if (random_card_b == 0)
        cout << "No card given to Team B" << endl;
    // Check if a yellow card is given
    else if (random_card_b == 1){
        cout << "A YELLOW card has been given to Team B" << endl;
        team_b_yellow_cards += 1;
    // Check if a red card is given
    } else if (random_card_b == 2){
        cout << "A RED card has been given to Team B" << endl;
        team_b_red_cards += 1;
    }
}

void goal_check_a (int random_goal_a, int &team_a_score, int &shots_on_target_by_a, int &shots_off_target_by_a, int &blocked_shots_a) {
    // Check if goal was scored
    if (random_goal_a == 0){
        cout << "GOALLL! for A" << endl;
        team_a_score += 1; 
        shots_on_target_by_a += 1;
    // Check if a save was made
    } else if (random_goal_a == 1){
        cout << "SAVED by the B goalkeeper/last defender" << endl;
        shots_on_target_by_a += 1;
        blocked_shots_a += 1;
    // Check if a miss occurred
    } else if (random_goal_a == 2){
        cout << "Team A MISSED THE NET" << endl;
        shots_off_target_by_a += 1;
    // Check if a block was made
    } else if (random_goal_a == 3){
        cout << "BLOCKED by a player on B who is not the last defender" << endl;
        shots_off_target_by_a += 1;
        blocked_shots_a += 1;
    }
}

void goal_check_b (int random_goal_b, int &team_b_score, int &shots_on_target_by_b, int &shots_off_target_by_b, int &blocked_shots_b) {
    // Check if a goal was scored
    if (random_goal_b == 0){
        cout << "GOALLL! for B" << endl;
        team_b_score += 1;
        shots_on_target_by_b += 1;
    // Check if a save was made
    } else if (random_goal_b == 1){
        cout << "SAVED by the Team A goalkeeper/last defender" << endl;
        shots_on_target_by_b += 1;
        blocked_shots_b += 1;
    // Check if a miss occurred
    } else if (random_goal_b == 2){
        cout << "Team B MISSED THE NET" << endl;
        shots_off_target_by_b += 1;
    // Check if a block was made
    } else if (random_goal_b == 3){
        cout << "BLOCKED by a player on A who is not the last defender" << endl;
        shots_off_target_by_b += 1;
        blocked_shots_b += 1;
    } 
}

void event_cases (int random, int &team_a_score, int &team_b_score, int &team_a_red_cards, int&team_a_yellow_cards, int &team_b_red_cards, int &team_b_yellow_cards, int &shots_on_target_by_a, int &shots_on_target_by_b, int &shots_off_target_by_a, int &shots_off_target_by_b, int &blocked_shots_a, int &blocked_shots_b, int &foul_a, int &foul_b) {
        // Event case when Team A shoots
        if (random == 1){
            cout << "Team A has shot at the target" << endl;
            int random_goal_a = (rand() % 4);
            goal_check_a(random_goal_a, team_a_score, shots_on_target_by_a, shots_off_target_by_a, blocked_shots_a);
        // Event case when Team B shoots
        } else if (random == 2){
            cout << "Team B has shot at the target" << endl;
            int random_goal_b = (rand() % 4);
            goal_check_b(random_goal_b, team_b_score, shots_on_target_by_b, shots_off_target_by_b, blocked_shots_b);
        // Event case when Team B commits a foul and a free kick is awarded
        } else if (random == 3){
            cout << "Team B has committed a foul and Team A was awarded a free kick" << endl;
            foul_b += 1;
            int random_goal_a = (rand() % 4);
            goal_check_a(random_goal_a, team_a_score, shots_on_target_by_a, shots_off_target_by_a, blocked_shots_a);
            int random_card_b = (rand() % 3);
            card_check_b (random_card_b, team_b_red_cards, team_b_yellow_cards);
        // Event case when Team A commits a foul and a free kick is awarded
        } else if (random == 4){
            cout << "Team A has committed a foul and Team B was awarded a free kick" << endl;
            int random_goal_b = (rand() % 4);
            foul_a += 1;
            goal_check_b(random_goal_b, team_b_score, shots_on_target_by_b, shots_off_target_by_b, blocked_shots_b);
            int random_card_a = (rand() % 3);
            card_check_a (random_card_a, team_a_red_cards, team_a_yellow_cards);
        // Event case when Team B commits a foul and a penalty is awarded
        } else if (random == 5){
            cout << "Team B has committed a foul close to the goal and Team A was awarded a penalty" << endl;
            int random_goal_a = (rand() % 3);
            foul_b += 1;
            goal_check_a(random_goal_a, team_a_score, shots_on_target_by_a, shots_off_target_by_a, blocked_shots_a);
        // Event case when Team A commits a foul and a penalty is awarded
        } else if (random == 6){
            cout << "Team A has committed a foul close to the goal and Team B was awarded a penalty" << endl;
            int random_goal_b = (rand() % 3);
            foul_a += 1;
            goal_check_b(random_goal_b, team_b_score, shots_on_target_by_b, shots_off_target_by_b, blocked_shots_b);
        }
}

int playgame() {
// Declaration of variables
    int total_events, // Total number of events in the game
    first_half_events, // Total number of events in the first half
    second_half_events, // Total number of events in the second half
    events_that_happened; // Total number of events that have occurred
    int team_a_score = 0, // Score for Team A
    team_b_score = 0; // Score for Team B
    int team_a_red_cards = 0, // Number of red cards for Team A
    team_a_yellow_cards = 0; // Number of yellow cards for Team A
    int team_b_red_cards = 0, // Number of red cards for Team B
    team_b_yellow_cards = 0; // Number of yellow cards for Team B
    int shots_on_target_by_a = 0, // Number of shots on target by Team A
    shots_on_target_by_b = 0; // Number of shots on target by Team B
    int shots_off_target_by_a = 0, // Number of shots off target by Team A
    shots_off_target_by_b = 0; // Number of shots off target by Team B
    int blocked_shots_a = 0, // Number of shots taken by Team A that have been blocked
    blocked_shots_b = 0; // Number of shots taken by Team B that have been blocked
    int foul_a = 0, // Number of fouls by Team A
    foul_b = 0; // Number of fouls by Team B

// Seed for random number generation 
    srand(time(0));

// The random number of events that occur during the game, produces random number from 1 to 30
    total_events = (rand() % 30) + 1;
    first_half_events = total_events/2; // Number of events in the first half
    second_half_events = total_events - first_half_events; // Number of events in the second half


// First half
    for (int events_that_happened = 0; events_that_happened < first_half_events; events_that_happened++)
    {
// Random number generation for event cases 1 to 6
        int random = (rand() % 6)+1;
        event_cases(random, team_a_score, team_b_score, team_a_red_cards, team_a_yellow_cards, team_b_red_cards, team_b_yellow_cards, shots_on_target_by_a, shots_on_target_by_b, shots_off_target_by_a, shots_off_target_by_b, blocked_shots_a, blocked_shots_b, foul_a, foul_b);
    }

// Halftime
// Displays halftime scores
    cout << "\nTEAM A SCORE: " << team_a_score << endl;
    cout << "TEAM B SCORE: " << team_b_score << endl;

// Displays Team A's halftime stats  
    cout << "\n----- Team A Stats -----" << endl;
    cout << "Yellow Cards: " << team_a_yellow_cards << endl;
    cout << "Red Cards: " << team_a_red_cards << endl;
    cout << "Shots on Target: " << shots_on_target_by_a << endl;
    cout << "Shots off Target: " << shots_off_target_by_a << endl;
    cout << "Shots blocked by the other team: " << blocked_shots_a << endl;
    cout << "Fouls: " << foul_a << endl;

// Displays Team B's halftime stats
    cout << "\n----- Team B Stats -----" << endl;
    cout << "Yellow Cards: " << team_b_yellow_cards << endl;
    cout << "Red Cards: " << team_b_red_cards << endl;
    cout << "Shots on Target: " << shots_on_target_by_b << endl;
    cout << "Shots off Target: " << shots_off_target_by_b << endl;
    cout << "Shots blocked by the other team: " << blocked_shots_b << endl;
    cout << "Fouls: " << foul_b << endl;
    cout << "\n-------- HALFTIME --------" << endl;
    cout << "\nPress enter to start second half" << endl;
    cin.get();

// Second half
        for (int events_that_happened = 0; events_that_happened < second_half_events; events_that_happened++)
    {
// Random number generation for event cases 1 to 6
        int random = (rand() % 6)+1;
        event_cases(random, team_a_score, team_b_score, team_a_red_cards, team_a_yellow_cards, team_b_red_cards, team_b_yellow_cards, shots_on_target_by_a, shots_on_target_by_b, shots_off_target_by_a, shots_off_target_by_b, blocked_shots_a, blocked_shots_b, foul_a, foul_b);    
    }

// Displays final scores
    cout << "\nEND OF GAME";
    cout << "\nTEAM A SCORE: " << team_a_score << endl;
    cout << "TEAM B SCORE: " << team_b_score << endl;

// Displays Team A's stats
    cout << "\n----- Team A Stats -----" << endl;
    cout << "Yellow Cards: " << team_a_yellow_cards << endl;
    cout << "Red Cards: " << team_a_red_cards << endl;
    cout << "Shots on Target: " << shots_on_target_by_a << endl;
    cout << "Shots off Target: " << shots_off_target_by_a << endl;
    cout << "Shots blocked by the other team: " << blocked_shots_a << endl;
    cout << "Fouls: " << foul_a << endl;

// Displays Team B's stats
    cout << "\n----- Team B Stats -----" << endl;
    cout << "Yellow Cards: " << team_b_yellow_cards << endl;
    cout << "Red Cards: " << team_b_red_cards << endl;
    cout << "Shots on Target: " << shots_on_target_by_b << endl;
    cout << "Shots off Target: " << shots_off_target_by_b << endl;
    cout << "Shots blocked by the other team: " << blocked_shots_b << endl;
    cout << "Fouls: " << foul_b << endl;

    return 0;
}

// Function to run game
int main() {
    playgame();
      return 0;
    }

   

