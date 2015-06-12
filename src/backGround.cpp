#include <backGround.h>

BackGround::BackGround(){
    this->i=0;

    this->score=0;
    sprintf(temp, "%d", score);//sprintf函数。。将int转化为char数组

    main.loadFromFile("background.png");
    copyright.loadFromFile("shoot_copyright.png");
    this->mainSprite.setTexture(this->main);

    heart1.loadFromFile("heart1.png");
    heart2.loadFromFile("heart2.png");
    heart3.loadFromFile("heart3.png");
    bloodSprite.setPosition(350,10);
    bloodSprite.setTexture(heart3);

    font.loadFromFile("BAUHS93.TTF");
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setColor(sf::Color::Black);
    scoreText.setString(temp);
    scoreText.setPosition(80,0);

    game_loading1.loadFromFile("game_loading1.png");
    game_loading2.loadFromFile("game_loading2.png");
    game_loading3.loadFromFile("game_loading3.png");
    game_loading4.loadFromFile("game_loading4.png");

    game_pause_nor.loadFromFile("game_pause_nor.png");
    game_pause_pressed.loadFromFile("game_pause_pressed.png");
    game_pauseSprite.setTexture(game_pause_nor);

    game_resume_nor.loadFromFile("game_resume_nor.png");
    game_resume_pressed.loadFromFile("game_resume_pressed.png");
    game_resumeSprite.setTexture(game_resume_nor);


    gameover.loadFromFile("gameover.png");
    gameoverSprite.setTexture(gameover);

}

BackGround::~BackGround(){}



bool BackGround::changePicture(){}

void BackGround::changeBlood(int life){
    switch(life){
        case 1:this->bloodSprite.setTexture(this->heart1);break;
        case 2:this->bloodSprite.setTexture(this->heart2);break;
        case 3:this->bloodSprite.setTexture(this->heart3);break;
    }
}

void BackGround::changeScore(int mark){
    if(mark==1){
        score+=100;
    }
    if(mark==2){
        score+=500;
    }
    if(mark==3){
        scoreText.setPosition(200,300);
    }
    sprintf(temp, "%d", score);
    scoreText.setString(temp);
}

sf::Sprite BackGround::mainplay(){
    return mainSprite;
}

sf::Sprite BackGround::bloodplay(){
    return bloodSprite;
}

sf::Text BackGround::textplay(){
    return scoreText;
}

sf::Sprite BackGround::pause_resume(int mark){
    if(mark==1){
        return game_pauseSprite;
    }
    if(mark==2){
        return game_resumeSprite;
    }
}

sf::Sprite BackGround::load(){

    i++;
        if(i<100){
            load_game.setTexture(copyright);
            load_game.setPosition(0,190);
        }
        else{
            load_game.setPosition(107,281);
            if(i<115){
                load_game.setTexture(game_loading1);
            }
            else if(i<130){
                load_game.setTexture(game_loading2);
            }
            else if(i<145){
                load_game.setTexture(game_loading3);
            }
            else {
                load_game.setTexture(game_loading4);
            }
            }

        return load_game;
}

sf::Sprite BackGround::over(){
    return gameoverSprite;
}
