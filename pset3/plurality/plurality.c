#include <cs50.h>
#include <stdio.h>
#include <string.h>

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
    //Iterate through candidates to determine if name is included
    for (int i = 0; i < candidate_count; i++)
    {
        //If name is valid vote, increment vote total and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    //vote not valid
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Sort candidates by descending vote total with a bubble sort
    candidate temp;

    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count - 1 - i; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }

    //Print the winner as sorted by most votes
    int maxVotes = candidates[candidate_count - 1].votes;

    //Iterate through sorted candidates array and print out all winners who achieved max vote count
    for (int i = candidate_count - 1; i >= 0; i--)
    {
        if (candidates[i].votes >= maxVotes)
        {
            printf("%s\n", candidates[i].name);
        }
        else
        {
            break;
        }
    }

    return;
}

