/*
 * GamePlayer.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: pavel
 */

#include "GamePlayer.h"

#include <Jupiter.h>
//#include <Ganymede/Ganimede.h>

using namespace std;
using namespace glm;
using namespace boost::filesystem;
using namespace boost::program_options;

//using namespace ganymede;
using namespace jupiter;

string usage = R"(
Usage  :
Example: ./GamePlayer -h                                            - for help
Example: ./GamePlayer -s json -g samples/Asteroids/Asteroids.json   - for sample from json file
Example: ./GamePlayer -s box -b samples/Box                         - for box sample
)";

string title =R"(Jupiter Game Player)";

/*
 * Code
 */

unique_ptr<Game> game;

unique_ptr<RenderVisitor>   render;
unique_ptr<NodeVisitor>     physics;

unique_ptr<Shader>          spriteShader;

unique_ptr<Node>            rootNode;

unique_ptr<Sprite>          bg,
                            flour,
                            box;

unique_ptr<Shape>           bgShape,
                            flourShape,
                            boxShape;

unique_ptr<Texture>         bgTexture,
                            flourTexture,
                            boxTexture;

unique_ptr<Controller>      boxController;

float viewRadius = 600.f;

float xAngle = 0.f;
float yAngle = 0.f;

const float Pi = 3.1415926;

template<typename T>
string to_string_(const T& wstr){
    string s{wstr.begin(), wstr.end()};
    return s;
}

bool createGameDirect(const variables_map& vm) {

    if (!vm.count("base"))
        throw runtime_error("base directory is invalid");

    File::setBase(vm["base"].as<string>());

    float width = 800, height = 480, depth = height;
    float div = 2.f;

//    auto proj = ortho(
//            -width/div,  width/div,
//            -height/div, height/div,
//            -depth/div,  depth/div);

    auto proj = perspective<float>(45.f, width / height, 10.f, 10000.f);

//    float z = viewRadius * sin(yAngle) * cos(xAngle);
//    float x = viewRadius * sin(yAngle) * sin(xAngle);
//    float y = viewRadius * cos(yAngle);

    float x = viewRadius * sin(xAngle);
    float y = viewRadius * sin(yAngle);
    float z = viewRadius * cos(xAngle);

    auto view = lookAt(vec3(x, y, z), vec3(0.f, 0.f, 0.f), vec3(0.f, 1.f, 0.f));

    render = make_unique_<RenderVisitor>(proj, view);

//    physics = make_unique_<PrintVisitor>();
    physics = make_unique_<NodeVisitor>();

    File vs { "Resources/sprite.vs" }, fs { "Resources/sprite.fs" };
    spriteShader = make_unique_<FileShader>(&vs, &fs);

    rootNode = make_unique_<Node>();

    PngImage bgImage { "Resources/bg.png" };
    bgTexture = make_unique_<ImageTexture>(&bgImage);
    bgShape = make_unique_<ImageShape>(&bgImage);

    bg = make_unique_<Sprite>();
    bg
        ->setProgram(spriteShader.get())
        ->setTexture(bgTexture.get())
        ->setShape(bgShape.get())
        ->setVisible(true)
        ->translateZ(-10.f)
        ->scale(.3f, .3f)
        ->setParent(rootNode.get())
    ;

    PngImage flourImage { "Resources/ground.png" };
//    PngImage flourImage { "Resources/ground_grass.png" };

    flourTexture = make_unique_<ImageTexture>(&flourImage);
    flourShape = make_unique_<ImageShape>(&flourImage);

    flour = make_unique_<Sprite>();
    flour
        ->setProgram(spriteShader.get())
        ->setTexture(flourTexture.get())
        ->setShape(flourShape.get())
        ->setVisible(true)
        ->translate(0.f, -190.f, 20.f)
        ->scale(.8f, .8f)
        ->setParent(rootNode.get())
    ;

    PngImage boxImage { "Resources/box.png" };
    boxTexture = make_unique_<ImageTexture>(&boxImage);
    boxShape = make_unique_<ImageShape>(&boxImage);

    box = make_unique_<Sprite>();
    box
        ->setProgram(spriteShader.get())
        ->setTexture(boxTexture.get())
        ->setShape(boxShape.get())
        ->setController(boxController.get())
        ->setVisible(true)
        ->translate(0.f, 150.f, 20.f)
        ->scale(.1f, .1f)
        ->setParent(rootNode.get())
    ;

    rootNode
        ->addNode(bg.get())
        ->addNode(flour.get())
        ->addNode(box.get())
        ->setVisible(true)
    ;

    game = make_unique_<Game>();
    game

        ->setRootNode(rootNode.get())
        ->setVisitors({physics.get(), render.get()})
        ->setWidth(width)
        ->setHeight(height)
    ;

    return true;
}

bool createGameJsonFile(const variables_map& vm) {

    if (!vm.count("game"))
        throw runtime_error("have no game file");

    path gameFile = vm["game"].as<string>();

    File::setBase(to_string_(gameFile.parent_path().native()));

    game = make_unique_<JsonGame>(to_string_(gameFile.filename().native()));

    return true;
}

bool createGame(int argc, char* argv[]) {
    options_description desc("General description");

    desc.add_options()
        ("help,h"   ,                  "Show help")
        ("sample,s" , value<string>(), "Select sample: box or json")
        ("game,g"   , value<string>(), "Path to game file")
        ("base,b"   , value<string>(), "Base directory");
    variables_map vm;

    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        cout << usage << endl;
        return false;
    }

    if (!vm.count("sample"))
        throw runtime_error("select sample");

    if (vm["sample"].as<string>() == "box") {
        createGameDirect(vm);
        return true;
    } else if (vm["sample"].as<string>() == "json") {
        createGameJsonFile(vm);
        return true;
    } else {
        throw runtime_error("select sample");
    }
    return false;
}

void draw() {

    box->rotateZ(.03f);

    game->draw();
}

void input() {
    game->input();
}

void keyboard(uint8_t key) {

//    cout << "key " << key << endl;

    switch (key) {
    case 'w': // up
        yAngle += .01f;
        break;
    case 's': // down
        yAngle -= .01f;
        break;
    case 'a': // left
        xAngle += .01f;
        break;
    case 'd': // right
        xAngle -= .01f;
        break;
    default:
        break;
    }

    float x = viewRadius * sin(xAngle);
    float y = viewRadius * sin(yAngle);
    float z = viewRadius * cos(xAngle);

    auto view = lookAt(vec3(x, y, z), vec3(0.f, 0.f, 0.f), vec3(0.f, 1.f, 0.f));
    render->setView(view);
}

std::string getTitle() {
    return "Jupiter Game Player";
}

int getWidth() {
    if (!game)
        throw runtime_error("game is invalid");
    return game->getWidth();
}

int getHeight() {
    if (!game)
        throw runtime_error("game is invalid");
    return game->getHeight();
}

