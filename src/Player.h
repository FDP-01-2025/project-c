struct Player
{
    int life = 3;
    int lifeMax = 3;
    int attack = 1;
    int items[2] = {0};

    void damage();
    void useItem();
    void addItem();
    bool alive();
};
