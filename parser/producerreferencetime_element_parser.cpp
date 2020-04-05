/*******************************************************************************
 * Copyright 2020 Vinod Damodaran
 *
 * Use of this source code is governed by a MIT-style license that can be found
 * in the LICENSE file.
 *******************************************************************************/

#include "producerreferencetime_element_parser.h"
#include "producerreferencetime.h"

#include "descriptor_element_parser.h"
#include "descriptor.h"
#include "utils.h"


namespace dash {
namespace mpd {

bool ProducerReferenceTimeElementParser::ParseStart(
    const std::string &element_name, ElementBase *elem_out,
    const char **attrib) {
  ProducerReferenceTime *elem = static_cast<ProducerReferenceTime*>(elem_out);
  for (int i = 0; attrib[i]; i += 2) {
    IF_ATTRIB_MATCHES("id") {
      elem->id_ = strtoul(attrib[i + 1], NULL, 10);
    } else IF_ATTRIB_MATCHES("inband") {
      elem->inband_ = Utils::ConvertToBool(attrib[i + 1]);
    } else IF_ATTRIB_MATCHES("type") {
      elem->type_ = attrib[i + 1];
    } else IF_ATTRIB_MATCHES("applicationScheme") {
      elem->application_scheme_ = attrib[i + 1];
    } else IF_ATTRIB_MATCHES("wallClockTime") {
      elem->wall_clock_time_ = attrib[i + 1];
    } else IF_ATTRIB_MATCHES("presentationTime") {
      elem->presentation_time_ = strtoul(attrib[i + 1], NULL, 10);
    } else {
      const char *tmp_attribs[3] = { attrib[i], attrib[i + 1], nullptr };
      ElementBaseParser::ParseStart(element_name, elem_out, tmp_attribs);
    }
  }
  return true;
}

ElementBase* ProducerReferenceTimeElementParser::CreateElement(
    const std::string &element) const {
  return new ProducerReferenceTime();
}

void ProducerReferenceTimeElementParser::AttachChildElementToParent(
    ElementBase *parent, ElementBase *child) {
  ProducerReferenceTime *elem = static_cast<ProducerReferenceTime*>(parent);
  const std::string &child_name = child->GetName();
  if (child_name == "UTCTiming") {
    elem->utc_timing_ = static_cast<Descriptor*>(child);
  } else {
    ElementBaseParser::AttachChildElementToParent(parent, child);
  }
}

ElementBaseParser* ProducerReferenceTimeElementParser::CreateChildParser(
    const std::string &name, ElementBaseParser *parent) {
  std::unique_ptr<ElementBaseParser> parser;
  if (name == "UTCTiming") {
    parser = std::make_unique < DescriptorElementParser > (name, parent);
  } else {
    return ElementBaseParser::CreateChildParser(name, parent);
  }
  ElementBaseParser *raw_parser = parser.get();
  InsertChildParser(name, std::move(parser));
  return raw_parser;
}

} // namespace mpd
} // namespace dash
