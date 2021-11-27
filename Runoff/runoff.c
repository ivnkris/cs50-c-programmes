#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate found set preferences
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    // If candidate doesn't exist return false
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Loop through voters
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through candidates
        for (int j = 0; j < candidate_count; j++)
        {
            // Check until find highest preference candidate that is still running
            if (candidates[preferences[i][j]].eliminated == false)
            {
                // Increase number of votes
                candidates[preferences[i][j]].votes++;
                // Break out from loop as already found highest preference candidate for current voter
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Loop through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate i has more than half of the votes print their name and return true
        if (candidates[i].votes > (float) voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // If no candidate has more than half of the votes return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Set min_votes to highest possible vote count
    int min_votes = voter_count;

    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate is still running and votes lower that previous minimum reset min_votes
        if (candidates[i].eliminated == false && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }

    // Return minimum votes
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Set counters for candidates with minimum votes and remaining candidates
    int min_count = 0;
    int remaining_candidates = 0;

    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate is still running and they have min votes increase both counters
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            min_count++;
            remaining_candidates++;
        }
        // Else if candidate still running increase remaining_candidates counter (will ignore eliminated candidates)
        else if (candidates[i].eliminated == false)
        {
            remaining_candidates++;
        }
    }

    // If all candidates have min votes return true
    if (min_count == remaining_candidates)
    {
        return true;
    }
    // Otherwise return false
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate has min votes eliminate candidate
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
