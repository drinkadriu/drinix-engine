#ifndef Component_h
#define Component_h

class Entity;

class Component
{
protected:
	Component(char*);
	Component(char*, Entity*);
	bool isActive = true;
	bool isSleep = false;
	float SleepTime = 0.f;
public:
	Entity* ThisEnt;
	float lesh = 1.f;
	char* Type;
	friend bool operator==(const Component& left, const Component& right){
		return ((left.Type == right.Type));
	}
	friend bool operator!=(const Component& left, const Component& right){
		return !(left == right);
	}
	void SetType(char*);
	bool GetActive() { return isActive; }
	void SetActive(bool newa) { isActive = newa; }
	virtual void Sleep(float time) {
		if (!isSleep) {
			isSleep = true;
			SleepTime = time;
			cout << "CompType: " << Type << endl;
			cout << "Component Will Sleep for: " << SleepTime << endl;
		}
	}
	void UpdateSleep();
	virtual void Awake() {};
	virtual void Start() {};
	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void OnEnabled() {};
	virtual ~Component();
};
#endif