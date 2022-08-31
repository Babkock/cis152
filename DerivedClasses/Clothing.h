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

#endif

