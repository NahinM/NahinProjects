board = [" "," "," "," "," "," "," "," "," "]

def frame():
    print("   |   |   ")
    print(f" {board[0]} | {board[1]} | {board[2]} ")
    print("   |   |   ")
    print("---|---|---")
    print("   |   |   ")
    print(f" {board[3]} | {board[4]} | {board[5]} ")
    print("   |   |   ")
    print("---|---|---")
    print("   |   |   ")
    print(f" {board[6]} | {board[7]} | {board[8]} ")
    print("   |   |   ")
frame()


def isWin():
    winCombo = [
        [0,1,2],
        [3,4,5],
        [6,7,8],
        [0,3,6],
        [1,4,7],
        [2,5,8],
        [0,4,8],
        [2,4,6]
    ]

    for cells in winCombo:
        a = board[cells[0]]
        b = board[cells[1]]
        c = board[cells[2]]
        if a!=" " and a==b and b==c:
            return True
    return False


move = 0
char = ["X","O"]
while move!=9:
    print("Enter the cell no.")
    x = int(input(f"Player{char[move%2]}: "))
    if 1<=x<=9 and board[x-1]==" ":
        board[x-1] = char[move%2]
        move+=1
        frame()
    else:
        print("Not a valid position.")
    if isWin():
        print(f"Player{char[(move+1)%2]} Won!!")
        break
    elif move==9:
        print("Match Draw")
        break
