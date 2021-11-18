import time
import random
import sys

#### PLAYER VARIABLES
characterName = ""
wep = 0
weapon = ""
headArm = 0
headArmor = "None"
chestArm = 0
chestArmor = "None"
larmArm = 0
larmArmor = "None"
rarmArm = 0
rarmArmor = "None"
llegArm = 0
llegArmor = "None"
rlegArm = 0
rlegArmor = "None"
equipment = 0
equipmentDisplay = "None"
level = 1
xp = 0
maxXP = 50
hp = 30
mp = 15
sp = 20
gold = 0
str = 0
attributePoints = 0
skillPoints = 0
dmg = 0
minDMG = 1
maxDMG = 4
mDMG = 0
mMinDMG = 0
mMaxDMG = 0
spell_1 = 0
spell_2 = 0
spell_3 = 0
spell_4 = 0
defe = 0
dmgBlocked = 3
counterChance = 10
counter = 0
counterDMG = 0
counterMinDMG = int(minDMG * 2.5)
counterMaxDMG = int(maxDMG * 3)
crit = 0
critChance = 5
location = "Unknown"
scene = 0
userCommand = -1
inventory = [""]
items = [""]

#### ENEMY VARIABLES
enemy = -1
enemyName = ""
enemyHP = 0
enemyMinDMG = 0
enemyMaxDMG = 0
enemyDMG = 0
minGold = 0
maxGold = 0
goldGain = 0
xpGain = 0
enemyLoot = 0

def startGame():
    print("You wake up not knowing where you are or how you got here.")
    time.sleep(3)
    global characterName
    characterName = input("Do you remember your name?")
    print("Ah yes " + characterName + " that was it. You must find out where you are and get out.")
    TutorialDungeon()


def TutorialDungeon():
    Display()
    global userCommand
    global scene
    userCommand = -1
    print("1) Move Forward \n2) Inventory \n3) Leave Game")
    while userCommand < 1 or userCommand > 3:
        userCommand = int(input("Command: "))
    if userCommand == 1:
        scene += 1
        CheckScene()
    elif userCommand == 2:
        Inventory()
    elif userCommand == 3:
        print("")




def Display():
    CheckWeapon()
    CheckDeath()
    print(f"Location: {location}")
    print(f"Name: {characterName}" + "\n-----------------------------")
    print(f"Level: {level}         XP: -  [{xp}/{maxXP}]  -")
    print(f"Weapon [{weapon}]      Head Armor [{headArmor}]")
    print(f"Gold: {gold}g          Chest Armor [{chestArmor}]")
    print(f"Health: {hp}           Right Arm Armor [{rarmArmor}]")
    print(f"Mana: {mp}             Left Arm Armor [{larmArmor}]")
    print(f"Stamina: {sp}          Right Leg Armor [{rlegArmor}]")
    print(f"                       Left Leg Armor [{llegArmor}]")
    print("-----------------------------")


def CheckWeapon():
    global minDMG
    global maxDMG
    global weapon
    if wep == 0:
        weapon = "Fists"
        minDMG = 1 + (str/5)
        maxDMG = 4 + (str/5)

    elif wep == 1:
        weapon = "Pickaxe"
        minDMG = 4 + (str/5)
        maxDMG = 6 + (str/5)

    elif wep == 2:
        weapon = "Crude Iron Sword"
        minDMG = 5 + (str/5)
        maxDMG = 8 + (str/5)

def Inventory():
    global wep
    print("------------Inventory------------")
    print(f"Weapon [{weapon}]")
    print(f"Gold: {gold}g")
    print(inventory)
    print("To equip a weapon type equip then the name of your weapon. For example equipPickaxe.")
    print("1)Go Back")
    global userCommand
    userCommand = -1
    userCommand = input("Command: ")
    if userCommand == "1":
       CheckScene()

    elif userCommand == "equipPickaxe" and "Pickaxe" in inventory:
        wep = 1
        print("You equipped the Pickaxe.")
        CheckWeapon()
        CheckScene()

    elif userCommand == "equipCrudeIronSword" and "Crude Iron Sword" in inventory:
        wep = 2
        print("You equipped the Crude Iron Sword.")
        CheckWeapon()
        CheckScene()

def Town():
    print("*----------Town----------*")
    global userCommand


def Forest():
    global location
    global scene
    scene = 0
    location = "Forest"
    print("#######<<Forest>>#######")


def Battle():
    print("!################## [BATTLE] ##################!")
    print("You have encountered an Enemy!")
    global enemyName
    global enemy
    global enemyHP
    global enemyMaxDMG
    global enemyMinDMG
    global enemyDMG
    global minGold
    global maxGold
    global goldGain
    global gold
    global userCommand
    global dmg
    global crit
    global critChance
    global hp
    global location
    global xpGain
    global xp
    global enemyLoot
    global inventory
    global scene
    global counter
    global counterChance
    global counterMinDMG
    global counterMaxDMG
    global counterDMG
    userCommand = -1


    if location == "Unknown":
        enemy = random.randint(0,3)


    if enemy == 0:
        enemyName = "Goblin Underling"
        enemyHP = 10
        enemyMinDMG = 1
        enemyMaxDMG = 3
        enemyDMG = random.randint(enemyMinDMG, enemyMaxDMG)
        minGold = 0
        maxGold = 3
        goldGain = random.randint(minGold, maxGold)
        xpGain = 3

    elif enemy == 1:
        enemyName = "Goblin Miner"
        enemyHP = 13
        enemyMinDMG = 1
        enemyMaxDMG = 5
        enemyDMG = random.randint(enemyMinDMG, enemyMaxDMG)
        minGold = 1
        maxGold = 5
        goldGain = random.randint(minGold, maxGold)
        xpGain = 5

    elif enemy == 2:
        enemyName = "Goblin Demolitionist"
        enemyHP = 6
        enemyMinDMG = 3
        enemyMaxDMG = 7
        enemyDMG = random.randint(enemyMinDMG, enemyMaxDMG)
        minGold = 4
        maxGold = 9
        goldGain = random.randint(minGold, maxGold)
        xpGain = 8

    elif enemy == 3:
        enemyName = "Goblin Soldier"
        enemyHP = 15
        enemyMinDMG = 2
        enemyMaxDMG = 5
        enemyDMG = random.randint(enemyMinDMG, enemyMaxDMG)
        minGold = 5
        maxGold = 13
        goldGain = random.randint(minGold, maxGold)
        xpGain = 10

    print(f"[{enemyName}]")
    print(f"EnemyHP: {enemyHP}                       {items}")
    print("1) Basic Attack \n2) Spell \n3) Block")

    while userCommand < 1 or userCommand > 3 and enemyHP > 0 and hp >= 0:
        CheckDeath()
        userCommand = int(input("Command: "))
        if userCommand == 1:        #########ATTACKING
            dmg = random.randint(minDMG, maxDMG)
            crit = random.randint(0, 100)
            if crit <= critChance:
                dmg = random.randint(minDMG * 3, maxDMG * 2)
                print("******![CRITICAL HIT]!******")
            enemyHP -= dmg
            enemyDMG = random.randint(enemyMinDMG, enemyMaxDMG)
            hp -= enemyDMG
            print(f"You dealt {dmg} Damage \n{enemyName} dealt {enemyDMG} Damage")
            time.sleep(2.5)
            Display()
            print(f"[{enemyName}]")
            print(f"EnemyHP: {enemyHP}")
            print("1) Basic Attack \n2) Spell \n3) Block")
            userCommand = -1

        elif userCommand == 2:      #######SPELLS
            if spell_1 and spell_2 and spell_3 and spell_4 > 0:
                print("Which spell do you want to use?")
                userCommand = int(input("Command: "))
            else:
                print("You have no spells to cast.")
                userCommand = -1

        elif userCommand == 3:     ######BLOCKING
            enemyDMG = random.randint(enemyMinDMG, enemyMaxDMG)
            enemyDMG -= dmgBlocked
            if enemyDMG < 0:
                enemyDMG = 0
            hp -= enemyDMG
            counter = random.randint(0, 100)
            counterDMG = random.randint(counterMinDMG, counterMaxDMG)
            if counter <= counterChance:
                enemyHP -= counterDMG
                print("<>>><<<>>>COUNTER ATTACK<>>><<<>>>")
                print(f"You countered for {counterDMG} Damage")
            print(f"You blocked {dmgBlocked} Damage")
            print(f"{enemyName} dealt {enemyDMG} Damage")
            time.sleep(2.5)
            Display()
            print(f"[{enemyName}]")
            print(f"EnemyHP: {enemyHP}")
            print("1) Basic Attack \n2) Spell \n3) Block")
            userCommand = -1

        elif userCommand == 4:
            print()

        if enemyHP <= 0:
            gold += goldGain
            xp += xpGain
            enemyLoot = random.randint(0, 10)
            if enemy == 1 and enemyLoot >= 7:
                print("You have found an Iron Pickaxe")
                inventory.append("Pickaxe")

            elif enemy == 2 and enemyLoot >= 6:
                print("You have found Dynamite. ")
                inventory.append("Dynamite")
                items.append("Dynamite")

            elif enemy == 3 and enemyLoot >= 8:
                print("You have found a Crude Iron Sword")
                inventory.append("Crude Iron Sword")

            print(f"You have slain {enemyName} \nYou recieved {goldGain}g \nYou recieved *{xpGain}XP*")
            scene += 1
            CheckScene()
            break


def CheckScene():
    global userCommand
    global gold
    global inventory
    global scene
    if location == "Unknown" and scene == 1:
        Battle()

    elif location =="Unknown" and scene == 2:
        userCommand == -1
        print("You find a dungeon room. \nDo you want to go inside?")
        print("1)Go Inside \n2)Keep Moving Forward \n3)Inventory")
        userCommand = int(input("Command: "))
        if userCommand == 1:
            print("You search the room and find a Health Potion and a bag of gold.")
            print("You found 20g.")
            gold += 20
            inventory.append("Health Potion")
            items.append("Health Potion")
            scene += 1
            CheckScene()

        elif userCommand == 2:
            scene += 1
            CheckScene()

        elif userCommand == 3:
            Inventory()

    elif location == "Unknown" and scene == 3:
        Battle()

    elif location == "Unknown" and scene == 4:
        Battle()

    elif location == "Unknown" and scene == 5:
        print("The rest of the goblins flee in cowardice. You spot a glimmer of light and follow it. ")
        print("You finally found your way out of the dungeon. There are tall trees and lots of wildlife.")
        Forest()

    elif location == "Unknown" and scene == 0:
        TutorialDungeon()






def CheckDeath():
    global hp
    global userCommand
    if hp <= 0:
        print("You have Fallen.")
        userCommand = input("Press any key to exit.")
        sys.exit(0)

def LevelUp():
    global level
    global xp
    global maxXP
    global skillPoints
    global attributePoints
    if xp > maxXP:
        level += 1
        maxXP += 25 * level


startGame()
