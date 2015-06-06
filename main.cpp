#include <iostream>
#include <string>
#include <list>
#include <memory>

class CTest {
public:
	CTest( std::string testName ) {
		std::cout << "Constructor - CTest" << std::endl;
		this->testName = testName;
	}
	
	~CTest() {
		std::cout << std::endl;
		std::cout << "Destructor - CTest" << std::endl;
		//Print the name of the object when it gets
		//deleted
		std::cout << "Name: " << testName << std::endl;
	}
	
	void addTest( std::shared_ptr<CTest> test ) {
		testList.push_back( test );
	}
	
private:
	std::string testName;
	//List of shared pointers (CTest)
	std::list<std::shared_ptr<CTest>> testList;
};




int main(int argc, const char **argv ) {
	CTest root( "Root" );
	
	//Explicit objects that also contain childs
	std::shared_ptr<CTest> leftSide( new CTest( "LeftSide" ) );
	std::shared_ptr<CTest> rightSide( new CTest( "RightSide" ) );
	
	//Add left and right side of the tree
	root.addTest( leftSide );
	root.addTest( rightSide );
	
	//Add objects to the left side
	//ATTENTION:
	// If smart pointers are used this way (no local variable that contains the
	// the smart pointer object) the creation of the raw pointer can and should
	// only depend on the constructor!!!
	leftSide->addTest( std::shared_ptr<CTest>( new CTest( "Object one" ) ) );
	leftSide->addTest( std::shared_ptr<CTest>( new CTest( "Object two" ) ) );
	//Add objects to the right side
	rightSide->addTest( std::shared_ptr<CTest>( new CTest( "Object three" ) ) );
	rightSide->addTest( std::shared_ptr<CTest>( new CTest( "Object four" ) ) );
	rightSide->addTest( std::shared_ptr<CTest>( new CTest( "Object five" ) ) );
	
	
	return 0;
}
