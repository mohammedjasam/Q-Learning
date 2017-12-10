import sys
import random


"""__________________GLOBAL VARIABLES__________________"""

# Q-Learning
Alpha = 0.1 # Learning rate (FIXED NOW)
DiscountFactor = 0.1 # Considers discounted rewards after time t
States = 100
Actions = 4
Q = [] # 2D Array to store States and their Actions

# Map
H = 10 # Height of the Map
W = 10 # Width of the Map
Map = [] # The 2D array to store the Map of the basement
Policy = []
DonutPresentOnMap = False # Bool value to keep track of the presence of donut


# Tinny Tim
X = 4 # Initial X Coordinate
Y = 4 # Initial Y Coordinate


"""__________________INITIALIZATIONS___________________"""

# Initializing the Q_MATRIX with default values, following Super Optimistic Method!
for i in range(States):
    GridActions = []
    for j in range(Actions):
        GridActions.append(1000) # Adding 1000 to each action
    Q.append(GridActions) # Adding the Actions List to the original Q Matrix

# Creating the Map of the Basement!
for i in range(H):
    MapColumns = []
    for i in range(W):
        MapColumns.append(" ")
    Map.append(MapColumns)

## Setting the outer boundaries in the Map
for i in range(W):
    Map[0][i] = "W"

for i in range(W):
    Map[9][i] = "W"

for i in range(H):
    Map[i][0] = "W"

for i in range(H):
    Map[i][9] = "W"

## Setting the inner boundaries in the MapColumns
Map[6][4] = "W";
Map[7][4] = "W";
Map[8][4] = "W";
Map[4][6] = "W";
Map[5][6] = "W";
Map[6][6] = "W";
Map[2][4] = "W";
Map[2][5] = "W";
Map[2][6] = "W";
Map[2][2] = "W";
Map[3][2] = "W";
Map[4][2] = "W";

Policy = Map[:]

# Dropping Tim into the Map!
Map[X][Y] = "T"




"""__________________OUTPUT MODULES___________________"""

# This function prints the Map on the screen
def PrintMap():
    for i in range(H):
        for j in range(W):
            print(Map[i][j] + "   ", end='')
        print("\n")

# This function prints the Q values for each state and its actions
def PrintQ():
    for i in range(States):
        for j in range(Actions):
            print(str(Q[i][j]) + "   ", end='')
        print()

# This function will extract the best action for the state to print the policy
def PrintPolicy():
    for i in range(H):
        for j in range(W):
            if not (Policy[i][j] == "W"):
                S = 10 * i + j
                MaxQValue, Action = getStateProperties(Q[S])
                ActionMap = {0 : "^", 1 : "<", 2 : "v", 3 : ">"} # Top, Left, Down, Right
                Policy[i][j] = ActionMap[Action]
            print(Policy[i][i] + "   ", end='')
        print("\n")


"""__________________Q-LEARNING MODULES___________________"""

# This function returns the properties of the State requested!
def getStateProperties(State):
    MaxQValue = -sys.maxsize # Sets the value of MaxQValue to highest possible negative value!
    Action = -1

    for i in range(len(State)):
        if MaxQValue < State[i]:
            MaxQValue = State[i]
            Action = i
    return MaxQValue, Action

"""__________________MAP MODULES___________________"""
# Spawn at corners
def CornerDrop(x, y):
    global Map

    Map[x][y] = 'D'

# This function Spawns Donut with a probability of 0.25 on the map in on of the four corners
def SpawnDonut():
    global DonutPresentOnMap
    if DonutPresentOnMap == False:
        Probability = random.randint(0, 100)

        if Probability < 25:
            MapCorners = {0 : [1, 1], 1 : [1, 8], 2 : [8, 1], 3 : [8, 8]} # Dict with Possible corners on the map
            CornerProb = random.randint(0, 3) # Choosing which corner to spawn the donut at

            Location = MapCorners[CornerProb]
            CornerDrop(Location[0], Location[1]) # This function spwans the donut on map
            DonutPresentOnMap = True





def Q_Learning():
    print()



def main():
    iterations = 0
    while(not DonutPresentOnMap):
        SpawnDonut()
    # PrintMap() # Prints the Map
    PrintPolicy()
    # PrintQ() # Prints the Q Matrix
    # while(True):
    #     SpawnDonut() # This functions spawns donut with 0.25 prob in 1 of 4 corners
    #     MoveTim() # This function moves TinnyTim based on the Policy
    #
    #     if (iterations % 100000000 == 0):
    #         print( str(iterations*100000000/1000000000) + " Billion iterations completed!")
    #         PrintMap()
    #     iterations +=1 # Incrementing the i value!






""" THIS IS WHERE THE EXECUTION BEGINDS """
main() # Calls  the main function which runs the whole program!
