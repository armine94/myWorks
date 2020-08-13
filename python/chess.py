WHITE = "white"
BLACK = "black"


class Game:
    def __init__(self):
        self.playersturn = BLACK
        self.gameboard = {}
        self.placePieces()
        self.main()

    """two arrays of pieces for each player"""
    """8x8 piece array with references to these pieces"""
    def placePieces(self):
        pass

    """a main loop, which takes input, runs it through the parser,"""
    """asks the piece if the move is valid, and moves the piece if it is."""
    """if the move conflicts with another piece, that piece is removed."""
    """ischeck(mate) is run, and if there is a checkmate, the game prints a message as to who wins"""
    def main(self):
        while True:
            self.printBoard()
            startpos = self.parseInput()
            endpos = self.parseInput()
            pass

    """ascertain where the kings are, check all pieces of opposing color against those kings,
    then if either get hit, check if its checkmate"""
    def isCheck(self):
        pass

    """checks if any pieces in piece list can see the king"""
    """return True when pieces can see the king, else return False"""
    def canSeeKing(self, piecelist):
        pass
        for piece, position in piecelist:
            if "isValid":
                return True

    """input coordinates"""
    """first: which is figure need move"""
    """second: figure where need move"""
    def parseInput(self):
        try:
            a = input().split()
            b = input().split()
            return (a, b)
        except:
            print("error decoding input. please try again")
            return ((-1,-1),(-1,-1))


    """print board afther each moves"""
    def printBoard(self):
        pass

class Piece:

    def __init__(self,color,name):
        self.name = name
        self.position = None
        self.Color = color

    """check start position and end position corectted"""
    def isValid(self, start_pos, end_pos, Color, gameboard):
        pass
        if "valid":
            return True
        return False


    """checks if a position is on the board"""
    """return True when position is on the board, else return False"""
    def isInBounds(self,x,y):
        if x >= 0 and x < 8 and y >= 0 and y < 8:
            return True
        return False

    """checks if a single position poses no conflict to the rules of chess"""
    """return True when yes conflict, else return False"""
    def noConflict(self,gameboard,initialColor,x,y):
        pass
        if "isvalis position" :
            return True
        return False


class Knight(Piece):
    """check validation for Knight and position
    afther validation move figure"""
    def availableMoves(self, x, y, gameboard, Color = None):
        pass


class Rook(Piece):
    """check validation for Rook and position
    afther validation move figure"""
    def availableMoves(self, x, y, gameboard, Color = None):
        pass


class Bishop(Piece):
    """check validation for Bishop and position
    afther validation move figure"""
    def availableMoves(self, x, y, gameboard, Color = None):
        pass


class Queen(Piece):
    """check validation for Queen and position
    afther validation move figure"""
    def availableMoves(self, x, y, gameboard, Color = None):
        pass


class King(Piece):
    """check validation for King and position
    afther validation move figure"""
    def availableMoves(self, x, y, gameboard, Color = None):
        pass


class Pawn(Piece):
    """check validation for Pawn and position
    afther validation move figure"""
    def availableMoves(self, x, y, gameboard, Color = None):
        pass

def main():
    Game()

if __name__ == "__main__":
    main()
