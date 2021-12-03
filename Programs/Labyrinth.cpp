#include <thread>
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Entity
{
    string name;
    int hp;
    int maxHp;
    int stam;
    int def;
    int minDmg;
    int maxDmg;
    int dmg;
    int xPos;
    int yPos;
    int amb;

    bool death(int h)
    {
        if (h <= 0)
        {
            return true;
        }else 
        {
            return false;
        }
    }

    void resetStamina()
    {
        if (stam > 50)
        {
            stam = 50;
        }else if (stam < 0)
        {
            stam = 0;
        }
    }

};

void s(int i)
{
    std::this_thread::sleep_for(std::chrono::seconds(i));
}

void Intro()
{
    cout << "*************ACT 1 SCENE 1*************" << endl;
    cout << "On the Island of Crete around Evening time..." << endl;
    cout << "King Minos: I'm sick and tired of this damn bull. This bull continues to rampage and destroy my hard work. Why must we be cursed with this creature." << endl;
    s(3);
    cout << "Queen Pasiphae: It is beyond me my love. I know you are upset as I am as well. It pains me to see our beloved island plagued with this monster." << endl;
    s(3);
    cout << "King Minos: Is it the gods? What must I have done for me and my city to undergo such cruel punishment. " << endl;
    s(2);
    cout << "Queen Pasiphae: Have you considered offering a reward to anyone who can slay the bull? " << endl;
    s(2);
    cout << "King Minos: No I haven't, a brilliant idea my queen. You cease to remind me why you are my wife my love. " << endl;
    cout << "Guards! Spread the word around the kingdom that I will be offering a mound of wealth to anyone who is able to slay the bull." << endl;
    s(5);
    cout << "Guard: On it my King, with the word spread soon this bull will meet it's demise." << endl;
    s(2);
    cout << "King Minos: Thank you my love. I will now go and gather a handsome reward and announce to all of this reward." << endl;
    s(2);
    cout << "Queen Pasiphae: Of course my love, go now." << endl;
    s(2);
    system("clear"); 
    cout << "*************ACT 1 SCENE 2*************" << endl;
    cout << "Enter Mount Olympus..." << endl;
    s(4);
    cout << "Poseidon: Who does Minos thinks he is! That damned OATHBREAKER! A mortal blinded by the title of King. Thinks he can mock me god of the ocean and not recieve judgement." << endl;
    s(3);
    cout << "Zeus: What troubles you Poseidon, what causes this rage I see now. " << endl;
    s(2);
    cout << "Poseidon: That damned King Minos asked for a white bull as sacrifice and he gave me a common bull in place of it. He broke his oath to me and that will not stand" << endl;
    s(2);
    cout << "Zeus: Mortals and their ignorance. They continue to test us and expect to win. They continue to attempt to fool us and they always fail. Their feeble attempts are laughable." << endl;
    s(3);
    cout << "Poseidon: If he loves that bull so much, i'm gonna engrave that bull into his life. Eros tomorrow at Dawn strike Mino's Wife with an arrow let her share her husband's love for the bull" << endl;
    s(3);
    cout << "Eros: It will be done Poseidon." << endl;
    s(3);
    system("clear"); 
    cout << "*************ACT 1 SCENE 3*************" << endl;
    cout << "Back to Crete at the Palace of Knossus..." << endl;
    cout << "Queen Pasiphae is in her bedroom alone in her thoughts after being shot with a harmful magical Arrow by Eros (God of Love)" << endl;
    s(3);
    cout << "Queen Pasiphae: I've never realized just how beautiful that bull really is. Even though it terrorizes our beloved land, I still can't help but feel for it." << endl;
    s(2);
    cout << "I've never truly captivated it's beauty until now. It's gorgeous horns tough horns, beautiful lushous tail, and magnificent body. Truly an amazing creature." << endl;
    s(2);
    cout << "I want to touch it and feel it's beauty across my fingertips maybe even more. I want to fully embrace the bull in all it's glory. Of course I love my husband but this bull" << endl;
    s(2); 
    cout << "is something else. Something bigger than even my husband. It's ashame it's an animal and not a man. I want nothing more than to be able to see what it's capable of doing " << endl;
    s(2);
    cout << "behind closed doors. There must be a way! Surely Daedalus would know. Surely he can construct some way for me to, enjoy, the bull. I must see him at once." << endl;
    s(3);
    system("clear"); 
    cout << "*************ACT 2 SCENE 1*************" << endl;
    cout << "Enter Daedualus's Workshop" << endl;
    cout << "Queen Pasiphae is having a discussion with Daedalus" << endl;
    s(3);
    cout << "Queen Pasiphae: I need you to build me something that will be able to get me close to the bull." << endl;
    s(3);
    cout << "Daedalus: But why my queen? Why must you get so close to the bull? Are you trying to get yourself killed?" << endl;
    s(3);
    cout << "Queen Pasiphae: I want to come face to face with the creature that is destroying our lands. I want to see it up close." << endl;
    s(3);
    cout << "Daedalus: Your out of your mind but if it was you wish, I shall build something capable of achieveing what you want." << endl;
    s(3);
    cout << "Queen Pasiphase: Thank you Daedalus, that is all I ask of you. I appreciate your services greatly. By when will you have it finished." << endl;
    s(3);
    cout << "Daedalus: In 4 days time, I shall bring to you your requested creation. I will notify you when I'm done." << endl;
    s(3);
    cout << "Finally after 4 days had past. Daedalus had finished his creation. A still, life scale figure of a bull was made and given to the Queen." << endl;
    s(3);
    cout << "The Queen fell in love with the creation as she did with the bull. She had the figure moved out into the open field where the Cretan Bull would finally approach it." << endl;
    s(5);
    cout << "As she hid inside she admired it's beauty and finally got what she wanted. She was able to fully enrapture the bull. Through the use of the figure she was finally able to have her lust quenched" << endl;
    s(4);
    cout << "The Cretan Bull had impregnated the Queen and shortly after she gave birth to a horrifying creature that would slaughter many. " << endl;
    s(4);
    system("clear");
    cout << "*************ACT 2 SCENE 2*************" << endl;
    cout << "We finally enter Athens and more specifically the House of Theseus." << endl;
    s(2);
    cout << "Aegeus: Why must you do this my boy? For what reason must you want to go?" << endl;
    s(3);
    cout << "Theseus: I want to bring to an end this nonsense. I want to bring to an end this sacrifice we must do every year. Why must our people be used as lamb for his monster." << endl;
    s(4);
    cout << "Aegeus: We must endure it for a little while longer my son. It was the only way to stop the attacks on our beloved city and keep King Minos at bay in order to buy time." << endl;
    s(4);
    cout << "Theseus: There must have been another way, but regardless my blood boils with rage, and it is this rage that I will use as fuel to end the life of whatever he has locked away." << endl;
    s(4);
    cout << "Aegeus: You know of my plans to build a fleet capable of contesting King Minos. I am almost there, this could end up doing more harm than good." << endl;
    s(3);
    cout << "Theseus: I care not for the continuation of the sacrifice of our beloved people. I will sail to Crete at once and lay to rest this so called monster." << endl;
    s(3);
    cout << "Aegeus: I beg of you Theseus, please do not go. For I won't know what I might do if you don't come back." << endl;
    s(3);
    cout << "Theseus: Have faith in me father and faith in the gods that they are watching over me. When I return look for the color of the sails on my ship." << endl;
    cout << "They will be white if I live or black if I die. Wish me luck father, I'm gonna prep to sail in 3 days time. " << endl;
    s(6);
    cout << "Aegeus: You fool! If there is nothing else I can say to keep you from going. Good luck then my son. " << endl;
    s(3);
    cout << "Theseus: Thank you father, I will put an end to this." << endl;
    system("clear");
    cout << "And so Theseus set sail for Crete. With a bright fire burning within him. Determined to slay what would became known as the minotaur. Would he fail or would he succeed." << endl;
    s(3);
    cout << "After Finally reaching Crete he met King Minos's daughter Princess Ariadne and the two fell in love on sight." << endl;
    s(3);
    cout << "It was due to this love that Princess Ariadne had given Theseus a thread that he could use in the Labyrinth in order to keep track of his movement and retrace his steps outside the Labryinth" << endl;
    s(3);
    cout << "Now it is time for you to traverse the Labyrinth and take on the challenge" << endl;
    s(4);

}

char lab[5][5] = { {'W', 'W', 'W', 'W', 'M'},
                   {'W', 'e', 'W', '*', '*'},
                   {'*', 'e', '*', 'e', 'W'},
                   {'*', 'W', 'W', '*', 'e'},
                   {'T', '*', 'e', 'W', 'W'} };

char emptyMap[5][5] = { {'*', '*', '*', '*', '*'},
                        {'*', '*', '*', '*', '*'},
                        {'*', '*', '*', '*', '*'},
                        {'*', '*', '*', '*', '*'},
                        {'T', '*', '*', '*', '*'} };

void Map(char l[5][5])
{
    for (int i  = 0; i < 5; i++)
    {
        for (int k = 0; k < 5; k++)
        {
            cout << l[i][k] << " ";
        }
        cout << endl;
    }
}

void Battle(Entity p, Entity e)
{
    e.hp = e.maxHp;
    char command;
    p.stam = 50;
    while (e.death(e.hp) == false)
    {
        system("clear");
        cout << "**********BATTLE**********" << endl;
        cout << e.name << endl;
        cout << "HP: " << e.hp << endl;
        cout << endl;
        cout << "Theseus" << endl;
        cout << "HP: " << p.hp << "     Stamina: " << p.stam << endl;
        cout << "Enter a command: \n";
        cout << "1 - Sword Slash (Sword Attack)" << endl;
        cout << "2 - Sword Thrust (Sword Attack)" << endl;
        cout << "3 - Haymaker (Fist Attack)" << endl;
        cout << "4 - Block (Block Enemy Attack %chance to counter attack)" << endl;
        cout << "5 - Rest (Regain Stamina)" << endl;
        cout << "6 - Drink Ambrosia (Regain HP or Health)" << endl;
        cin >> command;
    
        switch (command)
        {
        case '1':
            srand(time(0));
            if (rand()%10 >= 3 && p.stam > 10)
            {
                system("clear");
                p.dmg = (rand()%p.maxDmg) + p.minDmg;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 10;
                p.resetStamina();
                s(2);
            }else if (rand()%10 <= 2 && p.stam > 10)
            {
                system("clear");
                p.dmg = (rand()%p.maxDmg * 2) + p.minDmg * 2;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "*********CRITICAL SLASH*********" << endl;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 10;
                p.resetStamina();
                s(2);
            }
            else 
            {
                system("clear");
                cout << "Your attack missed, you might not have enough stamina..." << endl;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                s(2);
            }
            break;
        case '2':
            srand(time(0));
            if (rand()%10 >= 5 && p.stam > 7)
            {
                system("clear");
                p.dmg = (rand()%p.maxDmg - 2) + p.minDmg ;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 7;
                p.resetStamina();
                s(2);
            }else if (rand()%10 <= 2 && p.stam > 7)
            {
                system("clear");
                p.dmg = 15;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "*********FATAL BLOW*********" << endl;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 7;
                p.resetStamina();
                s(2);
            }
            else 
            {
                system("clear");
                cout << "Your attack missed, you might not have enough stamina..." << endl;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                s(2);
            }
            break;
        case '3':
            srand(time(0));
            if (rand()%10 >= 3 && p.stam > 3)
            {
                system("clear");
                p.dmg = (rand()%p.maxDmg - 4) + p.minDmg + 2;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 3;
                p.resetStamina();
                s(2);
            }else if (rand()%10 <= 2 && p.stam > 3)
            {
                system("clear");
                p.dmg = (rand()%p.maxDmg + 3) + p.minDmg + 3;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "*********CRITICAL HAYMAKER*********" << endl;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 3;
                p.resetStamina();
                s(2);
            }
            else 
            {
                system("clear");
                cout << "Your attack missed, you might not have enough stamina..." << endl;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                s(2);
            }
            break;
        case '4':
            srand(time(0));
            if (rand()%10 >= 3 && p.stam > 5)
            {
                system("clear");
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                int block = (rand()%8 + 1); 
                cout << "You block " << block << " from " << e.name << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg - block << endl;
                p.hp -= e.dmg - block;
                p.stam -= 5;
                p.resetStamina();
                s(2);
            }else if (rand()%10 <= 2 && p.stam > 5)
            {
                system("clear");
                p.dmg = (rand()%p.maxDmg) + p.minDmg;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << "*********COUNTER ATTACK*********" << endl;
                cout << "You hit " << e.name << " for " << p.dmg << endl;
                s(2);
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                e.hp -= p.dmg;
                p.stam -= 5;
                p.resetStamina();
                s(2);
            }
            else 
            {
                system("clear");
                cout << "Your block failed, you might not have enough stamina..." << endl;
                e.dmg = (rand()%e.maxDmg) + e.minDmg;
                cout << e.name << " hit you for " << e.dmg << endl;
                p.hp -= e.dmg;
                s(2);
            }
            break;
        case '5':
        {
            system("clear");
            srand(time(0));
            e.dmg = (rand()%e.maxDmg) + e.minDmg;
            int regainStam = (rand()%25 + 5);
            if (p.stam <= 50)
            {
                cout << "You rest and gain back " << regainStam << " stamina" << endl;
                s(2);
                p.stam += rand()%15 + 1;
            }
            if (p.stam > 50)
            {
                p.stam = 50;
            }
            cout << e.name << " hit you for " << e.dmg << endl;
            s(2);
            p.hp -= e.dmg;
            break;
        }
        case '6':
        {
            system("clear");
            srand(time(0));
            int heal = (rand()%p.maxHp  + 25);
            if ((p.hp <= p.maxHp) && (p.amb >= 0))
            {
                cout << "You drink ambrosia and heal " << heal << "HP " << endl;
                p.hp += heal;
                p.amb -= 1;
            }
            if (p.hp >= p.maxHp)
            {
                p.hp = p.maxHp;
            }
            cout << e.name << " hit you for " << e.dmg << endl;
            s(2);
            p.hp -= e.dmg;
            break;
        }
        default:
            cout << "Please Enter a Valid Command..." << endl;
            s(2);
            break;
        }
    }
}

void Labyrinth()
{
    //cout << "Element in Labyrinth: " << lab[4][1] << endl;
    bool gameOver = false;
    Entity player;
    player.name = "Theseus";
    player.hp = 100;
    player.maxHp = 100;
    player.def = 5;
    player.xPos = 4;
    player.yPos = 0;
    player.amb = 5;
    player.maxDmg = 15; //8
    player.minDmg = 2; //1
    player.stam = 50;

    Entity boss;
    boss.name = "Minotaur";
    boss.hp = 90;
    boss.maxHp = 90;
    boss.def = 10;
    boss.maxDmg = 20;
    boss.minDmg = 6;

    Entity enem;
    enem.name = "Prisoner";
    enem.hp = 15;
    enem.maxHp = 15;
    enem.def = 0;
    enem.maxDmg = 10;
    enem.minDmg = 0;

    Entity enem2;
    enem2.name = "Deranged Challenger";
    enem2.hp = 30;
    enem2.maxHp = 30;
    enem2.def = 5;
    enem2.maxDmg = 15;
    enem2.minDmg = 3;


    char command;

    while(gameOver == false)
    {   
        int enemyType;
        s(2);
        system("clear");
        Map(emptyMap);
        cout << endl;
        cout << endl;
        cout << "W = North " << endl;
        cout << "A = West " << endl;
        cout << "S = South " << endl;
        cout << "D = East " << endl;
        cout << "Enter a direction to move in the Labyrinth: "; 
        cin >> command;
        switch (command)
        {
            case 'W':
                srand(time(0));
                enemyType = (rand()%2);
                if (lab[player.xPos - 1][player.yPos] == '*')
                {
                    swap(lab[player.xPos][player.yPos], lab[player.xPos - 1][player.yPos]);
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos - 1][player.yPos]);
                    player.xPos -= 1;
                    cout << "You Moved to an Empty Space North..." << endl;
                    s(2);
                }else if (lab[player.xPos - 1][player.yPos] == 'W')
                {
                    cout << "You run into a Wall you cant move there..." << endl;
                    cout << "Choose a new direction..." << endl;
                    s(3);
                }else if (lab[player.xPos - 1][player.yPos] == 'e')
                {
                    cout << "You run into a deranged enemy in the Labyrinth. Prepare to fight..." << endl;
                    s(2);
                    if (enemyType == 1)
                    {
                        Battle(player, enem2);
                    }else 
                    {
                        Battle(player, enem);
                    }
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos - 1][player.yPos]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos - 1][player.yPos]);
                    lab[player.xPos][player.yPos] = '*';
                    player.xPos -= 1;
                    cout << "You killed an enemy and Moved North..." << endl;
                    s(2);
                }else if (lab[player.xPos - 1][player.yPos] == 'M')
                {
                    cout << "You've finally come across it. The moment you've been waiting for, the Minotaur. Prepare to fight..." << endl;
                    s(2);
                    Battle(player, boss);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos - 1][player.yPos]);
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos - 1][player.yPos]);
                    lab[player.xPos][player.yPos] = '*';
                    player.xPos -= 1;
                    gameOver = true;

                }
                break;
            case 'A':
                if (lab[player.xPos][player.yPos - 1] == '*')
                {
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos][player.yPos - 1]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos][player.yPos - 1]);
                    player.yPos -= 1;
                    cout << "You Moved to an Empty Space West..." << endl;
                }else if (lab[player.xPos][player.yPos - 1] == 'W')
                {
                    cout << "You run into a Wall you cant move there..." << endl;
                    cout << "Choose a new direction..." << endl;
                    s(3);
                }else if (lab[player.xPos][player.yPos - 1] == 'e')
                {
                    srand(time(0));
                    enemyType = (rand()%2);
                    cout << "You run into a deranged enemy in the Labyrinth. Prepare to fight..." << endl;
                    s(2);
                    if (enemyType == 1)
                    {
                        Battle(player, enem2);
                    }else 
                    {
                        Battle(player, enem);
                    }
                    swap(lab[player.xPos][player.yPos], lab[player.xPos][player.yPos - 1]);
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos][player.yPos - 1]);
                    lab[player.xPos][player.yPos] = '*';
                    player.yPos -= 1;
                    cout << "You killed an enemy and Moved West..." << endl;
                    s(2);
                }else if (lab[player.xPos][player.yPos - 1] == 'M')
                {
                    cout << "You've finally come across it. The moment you've been waiting for, the Minotaur. Prepare to fight..." << endl;
                    s(2);
                    Battle(player, boss);
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos][player.yPos - 1]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos][player.yPos - 1]);
                    lab[player.xPos][player.yPos] = '*';
                    player.yPos -= 1;
                    cout << "You killed an enemy and Moved West..." << endl;
                }
                break;
            case 'S':
                if (lab[player.xPos + 1][player.yPos] == '*')
                {
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos + 1][player.yPos]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos + 1][player.yPos]);
                    player.xPos += 1;
                    cout << "You Moved to an Empty Space South..." << endl;
                    s(2);
                }else if (lab[player.xPos + 1][player.yPos] == 'W')
                {
                    cout << "You run into a Wall you cant move there..." << endl;
                    cout << "Choose a new direction..." << endl;
                    s(3);
                }else if (lab[player.xPos + 1][player.yPos] == 'e')
                {
                    srand(time(0));
                    enemyType = (rand()%2);
                    cout << "You run into a deranged enemy in the Labyrinth. Prepare to fight..." << endl;
                    s(2);
                    if (enemyType == 1)
                    {
                        Battle(player, enem2);
                    }else 
                    {
                        Battle(player, enem);
                    }
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos + 1][player.yPos]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos + 1][player.yPos]);
                    lab[player.xPos][player.yPos] = '*';
                    player.xPos += 1;
                    cout << "You killed an enemy and Moved South..." << endl;
                    s(2);
                }else if (lab[player.xPos + 1][player.yPos] == 'M')
                {
                    cout << "You've finally come across it. The moment you've been waiting for, the Minotaur. Prepare to fight..." << endl;
                    Battle(player, boss);
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos + 1][player.yPos]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos + 1][player.yPos]);
                    lab[player.xPos][player.yPos] = '*';
                    player.xPos += 1;
                    cout << "You killed an enemy and Moved South..." << endl;
                }
                break;
            case 'D':
                if (lab[player.xPos][player.yPos + 1] == '*')
                {
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos][player.yPos + 1]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos][player.yPos + 1]);
                    player.yPos += 1;
                    cout << "You Moved to an Empty Space West..." << endl;
                    s(2);
                }else if (lab[player.xPos][player.yPos + 1] == 'W')
                {
                    cout << "You run into a Wall you cant move there..." << endl;
                    cout << "Choose a new direction..." << endl;
                    s(3);
                }else if (lab[player.xPos][player.yPos + 1] == 'e')
                {
                    srand(time(0));
                    enemyType = (rand()%3);
                    cout << "You run into a deranged enemy in the Labyrinth. Prepare to fight..." << endl;
                    s(2);
                    if (enemyType == 1)
                    {
                        Battle(player, enem2);
                    }else 
                    {
                        Battle(player, enem);
                    }
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos][player.yPos + 1]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos][player.yPos + 1]);
                    lab[player.xPos][player.yPos] = '*';
                    player.yPos += 1;
                    cout << "You killed an enemy and Moved West..." << endl;
                    s(2);
                }else if (lab[player.xPos][player.yPos + 1] == 'M')
                {
                    cout << "You've finally come across it. The moment you've been waiting for, the Minotaur. Prepare to fight..." << endl;
                    Battle(player, boss);
                    swap(emptyMap[player.xPos][player.yPos], emptyMap[player.xPos][player.yPos + 1]);
                    swap(lab[player.xPos][player.yPos], lab[player.xPos][player.yPos + 1]);
                    lab[player.xPos][player.yPos] = '*';
                    player.yPos += 1;
                    cout << "You killed an enemy and Moved West..." << endl;
                }
                break;
            default:
                cout << "Please Input a valid direction..." << endl;
        }
        
    }
}

void Outro()
{
    system("clear");
    cout << "*************FINALE*************" << endl;
    cout << "You have finally slain the minotaur and brought peace to the people of Athens. Parents can now rest easy without having to worry about sacrificing their children." << endl;
    s(4);
    cout << "Using the Thread that Princess Ariadne gifted you, you were able to retrace your steps in the labryinth and escape. You were able to accomplish what no other could." << endl;
    s(4);
    cout << "After finally killing the minotaur Theseus headed back to the city of Athens to let everyone know the good news and along he brought his new found love, King Minos's daughter with him Princess Ariadne." << endl;
    s(4);
    cout << "As he sailed back to Athens, him and his crew proudly and confidently raised the white flag for his father to see..." << endl;
    s(3);
    cout << "############################[* THE END *]############################" << endl;
}

int main()
{
    Intro();
    Labyrinth();
    Outro();
    return -1;
}