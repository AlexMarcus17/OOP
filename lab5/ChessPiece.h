//
// Created by User on 03.04.2024.
//

#ifndef OOPLAB5_CHESSPIECE_H
#define OOPLAB5_CHESSPIECE_H

#endif //OOPLAB5_CHESSPIECE_H

#include <iostream>
#include <cmath>
#include <string>

class ChessPiece {
protected:
    unsigned int positionX;
    unsigned int positionY;
    std::string name;
    bool color;

public:
    ChessPiece(unsigned int x, unsigned int y, const std::string& n, bool c)
            : positionX(x), positionY(y), name(n), color(c) {}

    unsigned int getPositionX() const { return positionX; }
    unsigned int getPositionY() const { return positionY; }
    std::string getName() const { return name; }
    bool getColor() const { return color; }

    void setPositionX(unsigned int x) { positionX = x; }
    void setPositionY(unsigned int y) { positionY = y; }

    bool movePiece(unsigned int newX, unsigned int newY) {

        return false;
    }
};

class Bishop : ChessPiece {
public:
    Bishop(unsigned int x, unsigned int y, bool c)
            : ChessPiece(x, y, "Bishop", c) {}

    bool movePiece(unsigned int newX, unsigned int newY)  {
        int abs1 = std::abs(static_cast<int>(newX-positionX));
        int abs2 = std::abs(static_cast<int>(newY-positionY));
        if(abs1 == abs2) {
            positionX = newX;
            positionY = newY;
            return true;
        }
        return false;
    }
};

class Rook : ChessPiece {
public:
    Rook(unsigned int x, unsigned int y, bool c)
            : ChessPiece(x, y, "Rook", c) {}

    bool movePiece(unsigned int newX, unsigned int newY)  {
        if (newX == positionX || newY == positionY) {
            positionX = newX;
            positionY = newY;
            return true;
        }
        return false;
    }
};

class Pawn : ChessPiece {
public:
    Pawn(unsigned int x, unsigned int y, bool c)
            : ChessPiece(x, y, "Pawn", c) {}

    bool movePiece(unsigned int newX, unsigned int newY)  {
        if(newX == positionX && newY == positionY + 1) {
            positionY = newY;
            return true;
        }
        return false;
    }
};

class Queen : ChessPiece {
public:
    Queen(unsigned int x, unsigned int y, bool c)
            : ChessPiece(x, y, "Queen", c) {}

    bool movePiece(unsigned int newX, unsigned int newY)  {
        return false;
    }
};

class King : ChessPiece {
public:
    King(unsigned int x, unsigned int y, bool c)
            : ChessPiece(x, y, "King", c) {}

    bool movePiece(unsigned int newX, unsigned int newY)  {
        return false;
    }
};
