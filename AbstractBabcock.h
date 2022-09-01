/***************************************
 * Name: Abstract Class
 * Author: Tanner Babcock
 * Created: September 1, 2022
 * Course: CIS 152 - Data Structures
 * Version: 1.0
 * OS: Void GNU/Linux
 * IDE: Emacs
 * Copyright : This is my own original work based
 * on specifications issued by our instructor.
 * Academic Honesty: I attest that this is my original
 * work. I have not used unauthorized source code,
 * either modified or unmodified. I have not given
 * other fellow student(s) access to my program.
**************************************/
#ifndef ABSTRACTBABCOCK_H
#define ABSTRACTBABCOCK_H

class Cycle {
private:
    int numberOfTires;
    int numberOfFlats;
public:
    /* constructors */
    Cycle(void);
    Cycle(int t);
    Cycle(int t, int f);

    /* getters and setters */
    int getNumberOfTires(void);
    void setNumberOfTires(int t);
    int getNumberOfFlats(void);
    void setNumberOfFlats(int f);

    /* methods */
    virtual void ride(void) = 0;
    virtual void stop(void) = 0;
};

class Unicycle : public Cycle {
private:
    std::string color;
public:
    /* constructors */
    Unicycle(void);
    Unicycle(std::string c);

    /* getters and setters */
    std::string getColor(void);
    void setColor(std::string c);

    /* methods */
    void ride(void);
    void stop(void);
};

class Bicycle : public Cycle {
private:
    std::string type;
    std::string color;
public:
    /* constructors */
    Bicycle(void);
    Bicycle(std::string t);
    Bicycle(std::string t, std::string c);

    /* getters and setters */
    std::string getType(void);
    void setType(std::string t);
    std::string getColor(void);
    void setColor(std::string c);

    /* methods */
    void ride(void);
    void stop(void);
};

class Tricycle : public Cycle {
private:
    std::string type;
    std::string color;
public:
    /* constructors */
    Tricycle(void);
    Tricycle(std::string t);
    Tricycle(std::string t, std::string c);

    /* getters and setters */
    std::string getType(void);
    void setType(std::string t);
    std::string getColor(void);
    void setColor(std::string c);

    /* methods */
    void ride(void);
    void stop(void);
};

#endif
