//
// Created by ASC_Student on 2/24/2025.
//

#include "Dog.hpp"
#include <iostream>
using namespace std;

Dog::Dog(string n) {
    name = n;
    strength = 50;
    x = 0;
    y = 1;
    secret = false;
}

Dog::Dog() {
    name = "Fluffy";
    strength = 50;
    x = 0;
    y = 0;
    secret = false;
}

bool Dog::changeStrength(int amt) {
/*changeStrength modifies the strength property by whatever amt is (basically adding here)
* It then calls printDog method to print out current information about the dog.
* It also checks to make sure that the dog object's strength is >0.
* If the dog object's strength is 0 or less, it calls the die method.
* It returns true if the strength is still >0 and false otherwise.
*/

    // I considered having this function accept a letter
    // To mark whether the dog was stepping on food or trap or normal space or wall
    // And then the strength change would be determined in here and not in MoveDog()
    // But the same reason as in MoveDog(), longer code has fewer bugs


	strength += amt; // changes strength by the amount

    if (strength > 0) { // if the dog is alive
        return true;
    } // if

    die();          // otherwise, the dog dies
    return false;
}

void Dog::die() {
/* This method just prints out a sad pathetic death of a dog message, letting everyone
* know of the demise of the dog object.  My message has ACK!!! and judgmental statements
* about how the user is a cruel, heartless person for letting a puppy dog die, but
* yours can be whatever you like.
*/

// judgement messages written by Matthew DeMark

	string judgement[10] = {"Wow… you really let that happen, huh? A defenseless dog, gone because of you.",
"Congratulations, you just failed at protecting a dog. Hope you're proud.",
"Was that your strategy? Because it looked like pure incompetence.",
"Woof woof… oh wait, the dog is dead. Thanks for that.",
"If dogs could scream, that one would’ve. But hey, at least you had fun, right?",
"That dog had dreams. You had one job. And now? Tragedy.",
"You let a dog die. A dog. What’s next? Pandas?",
"You monster. That dog trusted you.",
"Next time, try NOT being completely useless. Just a thought.",
"Imagine losing to a game where you just had to keep a dog alive. Couldn’t be me."};

    srand(time(0));
    cout << judgement[rand() % 10] << endl; 			// prints a judgemental line
}

void Dog::printDog() {
/* this method just prints out the basic information about the dog - its
*name and its current strength.
*/
	cout << "Name: " << name << endl << "Strength: " << strength << endl; // prints relevant information

    if (strength >= 100) {
        cout << "You have reached 100 strength! Secret Unlocked!" << endl;
        secret = true; 	// I might make an extra credit achievement set if I can figure out how to
        				// if there are only secrets, then they are just silly easter eggs
    }

    else if (strength > 50) {				    // more than starting health means this dog is well fed
        cout << "Your dog is very strong!" << endl;
    }
}

void Dog::won() {
/* again, just a message about the user's incredible prowess in successfully navigating the
* sweet little puppy dog through the evil forest to the other side.  You can make it whatever
* you like.
*/

// praise messages written by Matthew DeMark

	string praise[10] = {"Against all odds, through the twisted horrors of the forest, YOU prevailed! The dog lives, and so does your legacy!",
"A hero among mortals! The dog has seen the other side of the forest, all thanks to your masterful guidance!",
"The legends will sing of this day! You, the protector of canids, have defied fate itself!",
"Not all heroes wear capes. Some just have an unshakable will… and a dog. You did it!",
"The darkness of the forest quivered before you. The dog ambled to safety. And now? You are a champion!",
"They doubted you. They mocked you. But now, the dog walks free, and you stand victorious!",
"Through peril, through chaos, through near-certain doom… you delivered. The dog lives! The world rejoices!",
"The evil forest? Defeated. The dog? Saved. You? An unstoppable force of nature.",
"You saw danger. You laughed in its face. You carried that sweet little doggy to freedom like a true warrior!",
"A standing ovation. A roaring crowd. A dog that will tell tales of its legendary savior. You did it, and you did it gloriously!"};

    srand(time(0));
    cout << praise[rand() % 10] << endl; 			// prints a praising line

    // spatula designed by Matthew DeMark

    if(secret) {
        cout << "You got the secret! Your prize is this lucky spatula:"
        << " _______" << endl
        << "|       |" << endl
        << "|  ===  |" << endl
        << "|  ===  |" << endl
        << "|  ===  |" << endl
        << "|_______|" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "   |||" << endl
        << "  (|||)" << endl
        << "  (|||)" << endl
        << "  (|||)" << endl
        << "  (|||)" << endl
        << "  (|||)" << endl
        << "  =====" << endl;
    }
}

void Dog::reset() {
/* this method just resets the strength (for me it was 50) and the x and y to 0 and 0.
*
*/
	strength = 50;
    x = 0;
    y = 0;
}