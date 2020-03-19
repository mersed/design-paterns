/**
 * The idea in example bellow is that we have interface called "EnemyAttacker", which
 * can be used for all enemy attackers which we are going to create in our game.
 * Like, tank, fight jet and similar ...
 *
 * However, we have an EnemyRobot, which resembles to the EnemyAttacker, but it does not have
 * exactly the same methods.
 *
 * In order to be able to use the EnemyAttacker interfce, to make this EnemyRobot, to have
 * same behaviour as the rest of the enemies (which is what we want in well written and
 * unified code), then we will have to write adappter which will simply addapt Robot to
 * the generalized enemy.
 */
#include <iostream>

int random(int from, int to){
    return rand() % (to - from + 1) + from;
}

class EnemyAttacker
{
public:
    virtual void fireWepon() = 0;
    virtual void driveForward() = 0;
    virtual void assignDriver(std::string driverName) = 0;
};

class EnemyTank : EnemyAttacker
{
public:
    void fireWepon() override {
        std::cout << "Enemy tank does: " << random(0, 10) << " damage" << std::endl;
    }

    void driveForward() override {
        std::cout << "Enemy tank moves: " << random(0, 5) << " spaces" << std::endl;
    }

    void assignDriver(std::string driverName) override {
        std::cout << "Driver: " << driverName << " is driving a tank" << std::endl;
    }
};

class EnemyRobot
{
public:
    void smashWithHands()
    {
        std::cout << "Enemy robot causes: " << random(0, 10) << " damage with its hands" << std::endl;
    }

    void walkForward()
    {
        std::cout << "Enemy robot walks forward " << random(0, 5) << " spaces" << std::endl;
    }

    void reactToHuman(std::string driversName)
    {
        std::cout << "Enemy robot tramps on " + driversName << std::endl;
    }
};

class EnemyRobotAdapter : EnemyAttacker
{
public:
    EnemyRobot theRobot;

    EnemyRobotAdapter(const EnemyRobot &theRobot) : theRobot(theRobot) {}

    void fireWepon() override {
        theRobot.smashWithHands();
    }

    void driveForward() override {
        theRobot.walkForward();
    }

    void assignDriver(std::string driverName) override {
        theRobot.reactToHuman(driverName);
    }
};

int main() {
    srand(time(0));
    auto tank = EnemyTank{};
    tank.fireWepon();
    tank.driveForward();
    tank.assignDriver("Koala");

    EnemyRobot enemyRobot;
    EnemyRobotAdapter enemyRobotAdapter{enemyRobot};
    enemyRobotAdapter.fireWepon();
    enemyRobotAdapter.driveForward();
    enemyRobotAdapter.assignDriver("Bear");
    return 0;
}
