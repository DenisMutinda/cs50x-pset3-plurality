#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Loop over the whole candidate array
    for (int i = 0; i < candidate_count; i++)
    {
        
        // Over each iteration of the array, check whether the element
        // we are currently on matches the name passed.
        
        // If it matches, step into the if loop.
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Increase that candidates votes and return true.
            candidates[i].votes++;
            return true;
        }
    }
    
    // If name was not found, return false.
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int highest_vote = 0;           // Store the highest vote we have per election.
    string *winners;                // Store the winners of the election.
    winners = malloc(sizeof(string) * candidate_count);// Create a pointer to store all the winners.
    int winnersNumber = 0;                // Store number of winners.
    
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If that candidates vote is greater than the current highest vote ...
        // Change the value of highest vote.
        // Change the value of winner.
        // Include the name of the winner in our array to store winners.
        if (candidates[i].votes >= highest_vote)
        {
            highest_vote = candidates[i].votes;
            winnersNumber++;
            winners[winnersNumber - 1] = candidates[i].name; // -1 because arrays are zero indexed but variable starts at 1.
        }
    }
    
    // Iterate over the winners arrays and print each element in it.
    for (int i = 0; i < winnersNumber; i++)
    {
        printf("%s\n", winners[i]);
    }
}


