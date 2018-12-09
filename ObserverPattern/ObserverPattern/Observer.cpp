#include"Observer.h"
#include<vector>

class WeatherData : public Subject {
private:
	std::vector<Observer*> observer_list;
	float temperature;
	float humidity;
	float pressure;
public:
	WeatherData() {	}
	void registerObserver(Observer *o) {
		observer_list.push_back(o);
	}
	void removeObserver(Observer *o) {
		std::vector<Observer*>::iterator it;
		for (it = observer_list.begin(); it != observer_list.end();++it) {
			if (o->val == (*it)->val) {
				observer_list.erase(it);
			}
		}
	}
	void notifyObserver() {
		for (auto& observer : observer_list) {
			observer->update(temperature,humidity,pressure);
		}
	}
	void measurementsChanged() {
		notifyObserver();
	}
	void setMeasurements(float temp, float humi, float pres) {
		temperature = temp;
		humidity = humi;
		pressure = pres;
		measurementsChanged();
	}
};

class CurrentConditionsDisplay : public Observer, public DisplayElement {
private:
	float temperature;
	float humidity;
	Subject *weather_data;
public:
	CurrentConditionsDisplay(Subject *weatherdata){
		weather_data = weatherdata;
		weather_data->registerObserver(this);
	}
	void update(float temp, float humi, float pres) {
		temperature = temp;
		humidity = humi;
		display();
	}
	void display() {
		cout << "current conditions:temperature:" << temperature << " humidity:" << humidity << endl;
	}
};

int main() {
	WeatherData *weatherdata = new WeatherData();
	CurrentConditionsDisplay *currentcondition = new CurrentConditionsDisplay(weatherdata);
	weatherdata->setMeasurements(80, 65, 30.4f);
	weatherdata->setMeasurements(82, 70, 29.2f);
	weatherdata->setMeasurements(78, 90, 29.2f);
	getchar();
	return 0;
}