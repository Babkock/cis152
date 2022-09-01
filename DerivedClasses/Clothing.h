/***************************************
 * Name: Inheritance and Polymorphism: Derived Classes
 * Author: Tanner Babcock
 * Created: August 31, 2022
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
****************************************/
#ifndef CLOTHING_H
#define CLOTHING_H

class Clothing {
private:
	char size;
	std::string color;
public:
	/* constructors */
	Clothing();
	Clothing(char s);
	Clothing(char s, std::string c);

	/* getters and setters */
	void setSize(char s);
	char getSize(void);
	void setColor(std::string c);
	std::string getColor(void);

	/* methods */
	std::string wash(void);
	std::string pack(void);
	void print(void);
};

class Shirt : public Clothing {
private:
    std::string sleeves;
public:
    /* constructors */
    Shirt(std::string ss);
    Shirt(std::string ss, char s);
	Shirt(std::string ss, char s, std::string c);

	/* getters and setters */
    void setSleeves(std::string s);
    std::string getSleeves(void);

    /* methods */
    std::string wash(void);
	void print(void);
};

class Pants : public Clothing {
public:
    /* constructors */
    Pants(void);
    Pants(char s);
    Pants(char s, std::string c);

	/* methods */
    std::string wash(void);
    std::string hang(void);
};

#endif

