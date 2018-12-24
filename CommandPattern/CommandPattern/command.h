#pragma once
#include <iostream>
#include <string>

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class Light {
public:
	void on();
	void off();
};

class GarageDoor {
public:
	void open();
	void close();
};

class CeilingFan {
private:
	std::string location;
	int speed;
public:
	CeilingFan(std::string l);
	enum {
		HIGH,
		MEDIUM,
		LOW,
		OFF
	};
	void high();
	void medium();
	void low();
	void off();
	int get_speed();
};

class LightOnCommand : public Command {
private:
	Light *light;
public:
	LightOnCommand(Light *l);
	void execute();
	void undo();
};

class GarageDoorOpenCommand : public Command {
private:
	GarageDoor *garage_door;
public:
	GarageDoorOpenCommand(GarageDoor *gd);
	void execute();
	void undo();
};

class CeilingFanHighCommand : public Command {
private:
	CeilingFan *ceiling_fan;
	int prev_speed;
public:
	CeilingFanHighCommand(CeilingFan *cf);
	void execute();
	void undo();
};

class SimpleRemoteControl {
private:
	Command *slot;
public:
	void setCommand(Command *command);
	void buttonWasPressed();
	void undoButtonWasPressed();
};