

#include <iostream>
#include <string>

class Postac {
protected:
	

	
	
public:
	int zycie = 100;

	std::string walczenie = "brak";
	virtual std::string walcz() = 0;
	
	virtual ~Postac() {
		std::cout << "removing postac\n";
	}
};

class Rycerz : public Postac{

public:
	std::string walcz() {
		return walczenie;
	}

	Rycerz() {
		walczenie = "mieczem";
	}
	//int zycie;

	~Rycerz() {
		std::cout << "removing rycerz\n";
	}

private:
	//std::string walczenie;

};

class Lucznik : public Postac {
public:
	std::string walcz() {
		return walczenie;
	}

	Lucznik() {
		walczenie = "lukiem";
	}
	//int zycie;

	~Lucznik() {
		std::cout << "removing lucznik\n";
	}
private:



};

class Mag : public Postac {
public:
	std::string walcz() {
		return walczenie;
	}

	Mag() {
		walczenie = "czarami";
	}
	//int zycie;

	~Mag() {
		std::cout << "removing mag\n";
	}
private:



};


std::string powalcz(Postac& jakaspostac) {
	return jakaspostac.walcz();

}


int main()
{

	Rycerz a;
	Lucznik b;
	Mag c;

	Postac * wskp;

	wskp = &a;

	

	std::cout <<"Rycerz walczy " <<  wskp->walcz() << "\n";
	std::cout << "zycko: " <<  a.zycie << "\n";

	wskp = &b;
	std::cout << "Lucznik walczy  " << wskp->walcz() << "\n";
	wskp = &c;
	std::cout << "Mag  walczy  " << powalcz(*wskp) << "\n";



}


