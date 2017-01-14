#ifndef Entity_h
#define Entity_h

class World;

class Entity
{
private:
	unsigned ID;
	string Name;
	string Tag;
	bool IsStatic;
	bool IsActive;
	bool LastActive;
	int NumOfComponents = 0;
	Entity* Parent;
	vector <Entity*> AllChildren;
	friend bool operator==(const Entity& left, const Entity& right) {
		return ((left.Name == right.Name) && (left.Tag == right.Tag) && (left.IsStatic == right.IsStatic));
	}
	friend bool operator!=(const Entity& left, const Entity& right) {
		return !(left == right);
	}
protected:
	vector <Component*> AllComponents;
public:
	bool IsTarget = false;
	float KillTime = 0.f;
	World* ThisWorld;
	Entity& operator=(const Entity& other) {
		this->Name = other.Name;
		this->Tag = other.Tag;
		this->IsStatic = other.IsStatic;
		return *this;
	}

	template <typename T, typename ...Args>
	void AddComponent(Args && ...args) {
		NumOfComponents++;
		AllComponents.push_back(new T(std::forward<Args>(args)...));
	}

	template <typename T>
	T* GetComponent(int max = 0) {
		T t;
		int mor = 0;
		for (unsigned i = 0; i < AllComponents.size(); i++) {
			if (AllComponents.at(i)->Type == t.Type) {
				if (mor == max) {
					return dynamic_cast<T*>(AllComponents.at(i));
					break;
				}
				else {
					mor++;
					continue;
				}
			}
		}
		cout << "Entity: " << Name << " Does Not Have Component of Type: " << t.Type << endl;
	}
	template <typename T>
	bool HasComponent() {
		T t;
		for (unsigned i = 0; i < AllComponents.size(); i++) {
			if (AllComponents.at(i)->Type == t.Type) {
				return true;
				break;
			}
		}
	}

	template <typename T>
	void RemoveComponent() {
		T t;
		for (unsigned i = 0; i < AllComponents.size(); i++) {
			if (AllComponents.at(i)->Type == t.Type) {
				AllComponents.at(i)->~Component();
				AllComponents.erase(AllComponents.begin() + i);
				NumOfComponents--;
				break;
			}
		}
	}

	void RemoveAllComponents() {
		cout << "\n\"" << Name << "\", \"" << Tag << "\" , Is Removing: " << AllComponents.size() << " Components:" << endl;
		for (unsigned i = 0; i < AllComponents.size(); i++) {
			cout << "Removing Component(" << i + 1 << "): \"" << AllComponents.at(i)->Type << "\"" << endl;
			AllComponents.at(i)->~Component();
			AllComponents.erase(AllComponents.begin() + i);
		}
		NumOfComponents = 0;
	}

	int GetID();
	string GetName();
	string GetTag();

	void AddChild(Entity* Child) {
		Child->SetParent(this);
		AllChildren.push_back(Child);
	}
	void SetParent(Entity* NewParent) {
		if (Parent != nullptr)
			Parent->RemoveChild(Name, Tag);
		Parent = NewParent;
	}
	void PrintAllChildren() {
		cout << "\"" << Name << "\", \"" << Tag << "\" Tag, Is Printing: " << AllChildren.size() << " Children:" << endl;
		for (unsigned i = 0; i < AllChildren.size(); i++) {
			cout << "AllChildren(" << i + 1 << "): \"" << AllChildren.at(i)->Name << "\", \"" << AllChildren.at(i)->Tag << "\"" << endl;
		}
	}
	void PrintParent() {
		cout << "\"" << Name << "\" Has Parent: \"" << Parent->Name << "\", " << Parent->Tag << "\"" << endl;
	}
	template <typename T>
	T* GetComponentInParent() {
		T t;
		for (unsigned i = 0; i < Parent->AllComponents.size(); i++) {
			if (Parent->AllComponents.at(i)->Type == t.Type) {
				return dynamic_cast<T*>(Parent->AllComponents.at(i));
				break;
			}
		}
	}
	Entity* GetParent() {
		if (Parent != nullptr)
			return Parent;
	}
	Entity* GetChild(unsigned index) {
		if (AllChildren.size() >= index && index >= 0)
			return AllChildren.at(index);
	}
	Entity* GetChild(string name, string tag) {
		for (unsigned i = 0; i < AllChildren.size(); i++) {
			if (AllChildren.at(i)->GetName() == name && AllChildren.at(i)->GetTag() == tag) {
				return AllChildren.at(i);
				break;
			}
		}
	}
	Entity* GetChildName(string name) {
		for (unsigned i = 0; i < AllChildren.size(); i++) {
			if (AllChildren.at(i)->GetName() == name) {
				return AllChildren.at(i);
				break;
			}
		}
	}
	Entity* GetChildTag(string tag) {
		for (unsigned i = 0; i < AllChildren.size(); i++) {
			if (AllChildren.at(i)->GetTag() == tag) {
				return AllChildren.at(i);
				break;
			}
		}
	}
	void RemoveChild(unsigned index) {
		if (AllChildren.size() >= index && index >= 0)
			AllChildren.erase(AllChildren.begin() + index);
	}
	void RemoveChild(string name, string tag) {
		cout << AllChildren.size() << endl;
		if (!AllChildren.empty()) {
			for (unsigned i = 0; i < AllChildren.size(); i++) {
				if (AllChildren.at(i)->GetName() == name && AllChildren.at(i)->GetTag() == tag) {
					AllChildren.erase(AllChildren.begin() + i);
					break;
				}
			}
		}
	}
	void RemoveChildName(string name) {
		if (!AllChildren.empty()) {
			for (unsigned i = 0; i < AllChildren.size(); i++) {
				if (AllChildren.at(i)->GetName() == name) {
					AllChildren.erase(AllChildren.begin() + i);
					break;
				}
			}
		}
	}
	void RemoveChildTag(string tag) {
		if (!AllChildren.empty()) {
			for (unsigned i = 0; i < AllChildren.size(); i++) {
				if (AllChildren.at(i)->GetTag() == tag) {
					AllChildren.erase(AllChildren.begin() + i);
					break;
				}
			}
		}
	}
	void Kill(float time = 0.f);
	int GetAllCompsSize();
	bool GetStatic();
	bool GetActive() { return IsActive; };
	void SetActive(bool newActive) { LastActive = IsActive; IsActive = newActive; };
	int GetNumOfComponents() { return NumOfComponents; };
	virtual void Awake();
	void Start();
	virtual void Update();
	void FixedUpdate();
	void OnEnabled();
	void PrintAllComps();
	virtual void SetAll(string, string, bool isactive = true, bool isstatic = false);
	void PrintAll();
	void SetNewID();
	Entity(string name = "lol", string tag = "lol", bool isactive = true, bool isstatic = false);
	~Entity();
};
#endif