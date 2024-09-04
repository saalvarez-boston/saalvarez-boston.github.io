// File: nqueens.cxx, by Sergio A. Alvarez
// Solves the nonattacking chess queens problem using depth-first search 
// with backtracking (as outlined in a programming project in the book
// "Data Structures and other Objects using C++", by Main and Savitch)
// Relies on the stack class from the Standard Template Library

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

struct BoardPosition {
   int row;
   int col;
};


struct Move {
   int queen;
   BoardPosition pos;
};


bool attacking(BoardPosition pos1, BoardPosition pos2) {
   return ((pos1.row==pos2.row) || (pos1.col==pos2.col) 
            || (abs(pos1.row-pos2.row)==abs(pos1.col-pos2.col)));
}


bool conflict(stack<Move> s, BoardPosition tentpos) {
   while (!s.empty()) {
      if (attacking(s.top().pos, tentpos))
         return true;
      s.pop();
   }
   return false;
}


void display(stack<Move> s) {
   Move move;
   string line;
   while (!s.empty()) {
	line = "";
      	move = s.top(); s.pop();
      	for (int col=0; col < move.pos.col; col++)
		line += "  ";
	cout << line << "Q" << move.pos.row << endl;
   }
}


void initialize(int& n, Move& move, BoardPosition& position) {
   cout << "Enter the number of queens: ";
   cin >> n;
   assert(n > 0);
   cout << endl;
   position.row = 1;
   position.col = 0;
   move.pos = position;
   move.queen = 1;
}


int main () {

   stack<Move> s;          // stores queen id's/positions
   BoardPosition position; // position to try
   Move move;              // queen id + position
   int current_queen = 1;  // queen currently being positioned
   int n;                  // number of queens

   // read number of queens, initialize search variables
   initialize(n, move, position);
   
   do {
   // search for a position for the current queen
   //
   // the k-th queen goes in the k-th row
      position.row = current_queen;
   //
      if (position.col > n)
      // if previous position failed, move queen one column to the right
         position.col = move.pos.col + 1;
      else
      // start by placing current queen in column 1
         position.col = 1;
      // move queen right to avoid conflict 
      while (conflict(s, position) && (position.col <= n)) {
         position.col++;  
         cout << "trying column " << position.col << endl;
      }
      if (position.col > n) { // no admissible position found
         cout << "backtracking..." << endl;
         current_queen--; // backtrack to previous queen
         if (!s.empty()) {
            move = s.top(); s.pop(); // pop previous queen's tentative move
	}
         else { // out of luck - no solution
            cout << "no solution exists" << endl;
            return EXIT_FAILURE;
         }
      }
      else { // no conflict, so record move
         move.queen = current_queen;
         move.pos = position;
         s.push(move);
         cout << "tentatively placing queen " << current_queen
              << " at (row,col) = (" << move.pos.row
              << "," << move.pos.col << ")" << endl;
   	 display(s);
         current_queen++; // on to next queen
      }
   } while (current_queen <= n);
   cout << "Solution found:" << endl;
   display(s);
   return EXIT_SUCCESS;
}

