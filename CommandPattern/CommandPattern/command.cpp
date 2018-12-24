#include "command.h"

void Light::on() {
	printf("Light on!\n");
}

void Light::off() {
	printf("Light off!\n");
}

void GarageDoor::open() {
	printf("GarageDoor is open!\n");
}

void GarageDoor::close() {
	printf("GarageDoor is close!\n");
}

CeilingFan::CeilingFan(std::string l) {
	location = l;
	speed = OFF;
}
void CeilingFan::high() {
	speed = HIGH;
	printf("ceilingFan is high!\n");
}
void CeilingFan::medium() {
	speed = MEDIUM;
	printf("ceilingFan is medium!\n");
}
void CeilingFan::low() {
	speed = LOW;
	printf("ceilingFan is low!\n");
}
void CeilingFan::off() {
	speed = OFF;
	printf("ceilingFan is off!\n");
}
int CeilingFan::get_speed() {
	return speed;
}
LightOnCommand::LightOnCommand(Light *l) {
	light = l;
}

void LightOnCommand::execute() {
	light->on();
}

void LightOnCommand::undo() {
	light->off();
}

GarageDoorOpenCommand::GarageDoorOpenCommand(GarageDoor *gd) {
	garage_door = gd;
}

void GarageDoorOpenCommand::execute() {
	garage_door->open();
}

void GarageDoorOpenCommand::undo() {
	garage_door->close();
}

CeilingFanHighCommand::CeilingFanHighCommand(CeilingFan *cf) {
	ceiling_fan = cf;
}
void CeilingFanHighCommand::execute() {
	prev_speed = ceiling_fan->get_speed();
	ceiling_fan->high();
}
void CeilingFanHighCommand::undo() {
	if (prev_speed == ceiling_fan->HIGH) {
		ceiling_fan->high();
	}
	else if (prev_speed == ceiling_fan->MEDIUM) {
		ceiling_fan->medium();
	}
	else if (prev_speed == ceiling_fan->LOW) {
		ceiling_fan->low();
	}
	else if (prev_speed == ceiling_fan->OFF) {
		ceiling_fan->off();
	}
}

void SimpleRemoteControl::setCommand(Command *command) {
	slot = command;
}

void SimpleRemoteControl::buttonWasPressed() {
	slot->execute();
}

void SimpleRemoteControl::undoButtonWasPressed() {
	slot->undo();
}

int main() {
	SimpleRemoteControl *remote = new SimpleRemoteControl();
	Light *light = new Light();
	LightOnCommand *light_on = new LightOnCommand(light);
	GarageDoor *garagedoor = new GarageDoor();
	GarageDoorOpenCommand *garagedoor_open = new GarageDoorOpenCommand(garagedoor);
	CeilingFan *ceiling_fan = new CeilingFan("Living Room");
	CeilingFanHighCommand *ceilingfan_high = new CeilingFanHighCommand(ceiling_fan);

	remote->setCommand(light_on);
	remote->buttonWasPressed();
	remote->undoButtonWasPressed();
	remote->setCommand(garagedoor_open);
	remote->buttonWasPressed();
	remote->undoButtonWasPressed();
	remote->setCommand(ceilingfan_high);
	remote->buttonWasPressed();
	remote->undoButtonWasPressed();
	getchar();
	return 0;
}