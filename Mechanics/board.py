import numpy as np
import pandas as pd

## This file contains the main design of the game mechanics.
## Black Player = 0
## White Player = 1
## No piece     = 2

class Group():
    def __init__(self,color):
        self.coordinates = []
        self.color = color
    def addCoordinate(self,x,y):
        self.coordinates.append([x,y])
    def removeCoordinates(self,x,y):
        self.coordinates.remove([x,y])

class Board():
    
    def __init__(self, boardsize):
        self.board = [[0 for i in range(boardsize)] for j in range(boardsize)] 
        self.boardsize = boardsize
        self.Ko_buffer = None
        self.turn = 0 ## Black starts
    
    def __str__(self):
        boardsize = self.boardsize
        line = "   " + "_ "*boardsize
        linenumbers = "   "
        string = ""
        for col in range(boardsize):
            linenumbers += str(col) + " "
        string += linenumbers + "\n"
        for i in range(boardsize):
            string += line + "\n"
            row = " |"
            for j in self.board[i]:
                row += "" + str(j) + "|"
            string += str(i) + row + "\n"
        string += line
        return string
    def addHandicap(self, n, x, y):
        pass
        
    def addWhiteStone(self, x, y):
        if (x >= boardsize):
            raise Exception("Incompatible x input")
            return 
        if (y >= boardsize):
            raise Exception("Incompatible y input")
            return 
        if self.board[x][y] == 2:
            self.board[x][y] = 1
        else:
            raise Exception("Impossible to place stone")

    def addBlackStone(self, x, y):
        if (x >= boardsize):
            raise Exception("Incompatible x input")
            return 
        if (y >= boardsize):
            raise Exception("Incompatible y input")
            return 
        if self.board[x][y] == 2:
            self.board[x][y] = 0
        else:
            raise Exception("Impossible to place stone")
    def checkSuicide(x,y,color):
        pass
    def checkForCapture(self, x, y):
        boardsize = self.boardsize
        color = self.board[x][y]
        other = None
        if color == 1:
            other = 0
        else:
            other = 1
        
        if color != 2:
            if x > 0 and x < boardsize - 1 and y > 0 and y < boardsize - 1:
                if (self.board[x+1][y] == other) and   self.board[x][y+1] == other and self.board[x-1][y] == other and self.board[x][y-1] == other:
                    return True

            elif x == 0 and y > 0 and y < boardsize - 1:    
                if self.board[x+1][y] == other and   self.board[x][y+1] == other and self.board[x][y-1] == other:
                    return True
            
            elif x == boardsize - 1 and y > 0 and y < boardsize - 1:    
                if self.board[x-1][y] == other and   self.board[x][y+1] == other and self.board[x][y-1] == other:
                    return True

            elif x > 0 and x < boardsize - 1 and y == 0: 
                if self.board[x-1][y] == other and   self.board[x][y+1] == other and self.board[x+1][y] == other:
                    return True
            
            elif x > 0 and x < boardsize - 1 and y == boardsize -1: 
                if self.board[x-1][y] == other and   self.board[x][y-1] == other and self.board[x+1][y] == other:
                    return True
           
            elif x == 0 and y == 0:
                if self.board[1][0] == other and self.board[0][1] == other:
                    return True

            elif x == boardsize-1 and y == 0:
                if self.board[x-1][0] == other and self.board[x][1] == other:
                    return True

            elif y == boardsize-1 and x == 0:
                if self.board[1][y-1] == other and self.board[0][y] == other:
                    return True

            elif x == boardsize-1 and y == boardsize - 1:
                if self.board[x-1][y] == other and self.board[x][y-1] == other:
                    return True
        return False
    def updateKoBuffer(x,y):
        self.Ko_buffer = [x,y]
    def resetKoBuffer():
        self.Ko_buffer = None
    def playStone(x,y):
        ## will check for all the conditions before actually play
        ## conditions are, in this order:
        ##       1) There are no stones at (x, y)
        ##       2) Ko buffer
        ##       3) is suicide but captures something.
        ##       3) is not suicide 


board = Board(9)
print(board)





