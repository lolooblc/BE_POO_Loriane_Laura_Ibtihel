#ifndef DEVICES_H_
#define DEVICES_H_

class Devices {
	protected:
		static int nbDevices;
	public:
	Devices();
  //print the nature of the device
	virtual void WhoAmI();
};

#endif
