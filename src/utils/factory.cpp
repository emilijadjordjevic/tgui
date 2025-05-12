#include "utils/factory.h"

namespace factory {
    Element textLabel(const string& s) {
        return factory::create<TextLabel>(s);
    }
    
    // Element textLabel(const string& s, Size size) {
    //     return factory::create<TextLabel>(s);
    // }

    Element progressBar(float progress, Direction d) {
        return factory::create<ProgressBar>(progress, d);
    }

    Element progressBar(Size& size, float progress, Direction d) {
        return factory::create<ProgressBar>(size, progress, d);
    }

    Element borderInternal(Element e, int topBorder, int rightBorder, int bottomBorder, int leftBorder) {
        return factory::create<Border>(e, topBorder, rightBorder, bottomBorder, leftBorder);
    }

    Element borderInternal(Element e, char c, int topBorder, int rightBorder, int bottomBorder, int leftBorder) {
        return factory::create<Border>(e, c, topBorder, rightBorder, bottomBorder, leftBorder);
    }

    Element boldInternal(Element e) {
        return factory::create<Bold>(e);
    }

    Element strikethroughInternal(Element e) {
        return factory::create<Striketrough>(e);
    }

    Element underlineInternal(Element e) {
        return factory::create<Underline>(e);
    }

    Element italicInternal(Element e) {
        return factory::create<Italic>(e);
    }
    
    Container hbox(Size& s) {
        return factory::create<HBox>(s);
    }
    
    Container hbox(initializer_list<Element> elements) {
        return factory::create<HBox>(Elements(elements));
    }
    
    // Container hbox(Element e) {
    //     return hbox({e});
    // }
    
    Container hbox(Size& size, initializer_list<Element> elements) {
        return factory::create<HBox>(size, Elements(elements));
    }
    
    // Container hbox(Size& size, Element e) {
    //     return hbox(size, {e});
    // }
    
    Container vbox(Size& s) {
        return factory::create<VBox>(s);
    }
        
    Container vbox(initializer_list<Element> elements) {
        return factory::create<VBox>(Elements(elements));
    }
    
    // Container vbox(Element e) {
    //     return vbox({e});
    // }
    
    Container vbox(Size& size, initializer_list<Element> elements) {
        return factory::create<VBox>(size, Elements(elements));
    }
    
    // Container vbox(Size& size, Element e) {
    //     return hbox(size, {e});
    // }
}