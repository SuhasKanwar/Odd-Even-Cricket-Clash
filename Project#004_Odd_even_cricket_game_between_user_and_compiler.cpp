#include <iostream>
#include <random>
#include <climits>
#include <ctime>
using namespace std;
class odd_even
{
    public:
        int random(int n) // Random value generator
        {
            static bool seeded = false;
            if(!seeded)
            {
                srand(time(0));
                seeded = true;
            }
            return rand() % n + 1;
        }
        bool Toss(char toss_choice) // Toss
        {
            int toss, toss_result;
            cout<<"Enter your number for the toss (1 to 10): ";
            cin>>toss;
            toss_result = random(10) + toss;
            if(toss_choice == 'o')
            {
                if(toss_result % 2 != 0)
                {
                    cout<<"You won the toss.\n";
                    return true;
                }
                else
                {
                    cout<<"You lost the toss.\n";
                    return false;
                }
            }
            else if(toss_choice == 'e')
            {
                if(toss_result % 2 == 0)
                {
                    cout<<"You won the toss.\n";
                    return true;
                }
                else
                {
                    cout<<"You lost the toss.\n";
                    return false;
                }
            }
            else
            {
                cout<<"Invalid choice. Enter 'o' or 'e'.\n";
                return false;
            }
        }
        int batting_user() // Function for user batting
        {
            int run, runs = 0, compiler_num;
            cout<<"\nYou are batting now.\n";
            do
            {
                compiler_num = random(10);
                cout<<"Enter a number (1 to 10): ";
                cin>>run;
                if(run > 10)
                {
                    run = 10;
                }
                runs += run;
                cout<<"You scored: "<<run<<" runs. Total runs: "<<runs<<"\n";
            }
            while(compiler_num != run);
            return runs;
        }
        int batting_compiler() // Function for compiler batting
        {
            int run, runs = 0, compiler_run;
            cout<<"\nCompiler is batting now.\n";
            do
            {
                compiler_run = random(10);
                cout<<"Enter a number (1 to 10): ";
                cin>>run;
                if(run > 10)
                {
                    run = 10;
                }
                if(compiler_run != run)
                {
                    runs += compiler_run;
                    cout<<"Compiler scored: "<<compiler_run<<" runs. Total runs: "<<runs<<"\n";
                }
            }
            while(compiler_run != run);
            return runs;
        }
        void toss_victory_user(int &runs_user, int &runs_compiler, int &target) // Condition if the user wins the toss
        {
            int choice2;
            cout<<"\nYou won the toss. Choose:\n";
            cout<<"1 = Batting\n2 = Bowling\nWhat do you want: ";
            cin>>choice2;
            if(choice2 == 1)
            {
                cout<<"You chose to bat first.\n";
                runs_user = batting_user();
                target = runs_user; // Set the target score
                cout<<"The target score is: "<<target<<"\n";
                cout<<"Now it is time for your opponent to bowl.\n";
                runs_compiler = batting_compiler();
                cout<<"Total runs scored by the compiler: "<<runs_compiler<<"\n";
            }
            else if(choice2 == 2)
            {
                cout<<"You chose to bowl first.\n";
                runs_compiler = batting_compiler();
                target = runs_compiler; // Set the target score
                cout<<"The target score is: "<<target<<"\n";
                cout<<"Now it is time for you to bat.\n";
                runs_user = batting_user();
                cout<<"Total runs scored by you: "<<runs_user<<"\n";
            }
            else
            {
                cout<<"Invalid choice. Enter 1 or 2.\n";
                runs_user = 0;
                runs_compiler = 0;
                target = 0;
            }
        }
        void toss_victory_compiler(int &runs_user, int &runs_compiler, int &target) // Condition if the user loses the toss
        {
            int compiler_call;
            compiler_call = random(2); // Randomly chooses 1 or 2
            if(compiler_call == 1)
            {
                cout<<"\nCompiler chose to bat first. You will bowl now.\n";
                runs_compiler = batting_compiler();
                target = runs_compiler; // Set the target score
                cout<<"The target score is: "<<target<<"\n";
                cout<<"Now it is time for you to bat.\n";
                runs_user = batting_user();
                cout<<"Total runs scored by you: "<<runs_user<<"\n";
            }
            else if(compiler_call == 2)
            {
                cout<<"\nCompiler chose to bowl first. You will bat now.\n";
                runs_user = batting_user();
                target = runs_user; // Set the target score
                cout<<"The target score is: "<<target<<"\n";
                cout<<"Now it is time for the compiler to bat.\n";
                runs_compiler = batting_compiler();
                cout<<"Total runs scored by the compiler: "<<runs_compiler<<"\n";
            }
        }
};
int main()
{
    odd_even game;
    bool result;
    char choice1, toss_choice, start;
    int runs_user, runs_compiler, target;
    cout<<"Welcome to the Odd-Even Cricket Game!\n";
    cout<<"Do you want to play the odd/even game of cricket (y/n): ";
    cin>>start;
    while(start != 'n')
    {
        cout<<"\nReady for the toss (y/n): ";
        cin>>choice1;
        if(choice1 == 'y')
        {
            cout<<"Do you want to choose odd or even (o = odd, e = even): ";
            cin>>toss_choice;
            result = game.Toss(toss_choice);
            if(result)
            {
                game.toss_victory_user(runs_user, runs_compiler, target);
                // cout << "\nNow it is time for your opponent to bowl.\n";
                if(runs_user > runs_compiler)
                {
                    cout<<"Congratulations! You won the game.\n";
                }
                else if(runs_user < runs_compiler)
                {
                    cout<<"Compiler won the game. Better luck next time!\n";
                }
                else
                {
                    cout<<"It's a draw.\n";
                }
            }
            else
            {
                game.toss_victory_compiler(runs_user, runs_compiler, target);
                cout<<"\nNow it is time for you to bat.\n";
                if(runs_user > runs_compiler)
                {
                    cout<<"Congratulations! You won the game.\n";
                }
                else if(runs_user < runs_compiler)
                {
                    cout<<"Compiler won the game. Better luck next time!\n";
                }
                else
                {
                    cout<<"It's a draw.\n";
                }
            }
        }
        else if(choice1 == 'n')
        {
            cout<<"Okay, exiting the game.\n";
            break;
        }
        else
        {
            cout<<"Invalid choice. Enter 'y' or 'n'.\n";
        }
        cout<<"\nDo you want to play again (y/n): ";
        cin>>start;
    }
    return 0;
}