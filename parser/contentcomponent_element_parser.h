/*******************************************************************************
 * Copyright 2020 Vinod Damodaran
 *
 * Use of this source code is governed by a MIT-style license that can be found
 * in the LICENSE file.
 *******************************************************************************/

#ifndef DASH_CONTENTCOMPONENT_ELEMENT_PARSER_H_
#define DASH_CONTENTCOMPONENT_ELEMENT_PARSER_H_

#include "elementbase_parser.h"

namespace dash {
namespace mpd {

class ContentComponentElementParser: public ElementBaseParser {
    using ElementBaseParser::ElementBaseParser;

  public:
    bool ParseStart(const std::string &element_name, ElementBase *elem_out,
        const char **attrib) override;
    void AttachChildElementToParent(ElementBase *parent, ElementBase *child)
        override;
    ElementBase* CreateElement(const std::string &element) const override;
    ElementBaseParser* CreateChildParser(const std::string &name,
        ElementBaseParser *parent) override;

};

} // namespace mpd
} // namespace dash

#endif /* DASH_CONTENTCOMPONENT_ELEMENT_PARSER_H_ */
