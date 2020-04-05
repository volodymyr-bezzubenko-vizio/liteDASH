/*******************************************************************************
 * Copyright 2020 Vinod Damodaran
 *
 * Use of this source code is governed by a MIT-style license that can be found
 * in the LICENSE file.
 *******************************************************************************/

#ifndef DASH_SUBREPRESENTATION_ELEMENT_PARSER_H_
#define DASH_SUBREPRESENTATION_ELEMENT_PARSER_H_

#include "representationbase_element_parser.h"

namespace dash {
namespace mpd {

class SubRepresentationElementParser: public RepresentationBaseElementParser {
    using RepresentationBaseElementParser::RepresentationBaseElementParser;

  public:
    bool ParseStart(const std::string &element_name, ElementBase *elem_out,
        const char **attrib) override;
    ElementBase* CreateElement(const std::string &element) const override;
};

} // namespace mpd
} // namespace dash

#endif /* DASH_SUBREPRESENTATION_ELEMENT_PARSER_H_ */
