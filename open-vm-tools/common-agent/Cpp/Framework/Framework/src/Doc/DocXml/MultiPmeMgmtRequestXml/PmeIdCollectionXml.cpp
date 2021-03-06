/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/MultiPmeMgmtRequestDoc/CPmeIdCollectionDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/MultiPmeMgmtRequestXml/PmeIdCollectionXml.h"

using namespace Caf;

void PmeIdCollectionXml::add(
	const SmartPtrCPmeIdCollectionDoc pmeIdCollectionDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("PmeIdCollectionXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(pmeIdCollectionDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::deque<std::string> pmeIdVal =
			pmeIdCollectionDoc->getPmeIdCollection();
		CAF_CM_VALIDATE_STL(pmeIdVal);

		if (! pmeIdVal.empty()) {
			for (TConstIterator<std::deque<std::string> > pmeIdIter(pmeIdVal);
				pmeIdIter; pmeIdIter++) {
				const SmartPtrCXmlElement pmeIdXml =
					thisXml->createAndAddElement("pmeId");
				pmeIdXml->setValue(*pmeIdIter);
			}
		}
	}
	CAF_CM_EXIT;
}

SmartPtrCPmeIdCollectionDoc PmeIdCollectionXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("PmeIdCollectionXml", "parse");

	SmartPtrCPmeIdCollectionDoc pmeIdCollectionDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const CXmlElement::SmartPtrCElementCollection pmeIdChildrenXml =
			thisXml->findRequiredChildren("pmeId");

		std::deque<std::string> pmeIdVal;
		if (! pmeIdChildrenXml.IsNull() && ! pmeIdChildrenXml->empty()) {
			for (TConstIterator<CXmlElement::CElementCollection> pmeIdXmlIter(*pmeIdChildrenXml);
				pmeIdXmlIter; pmeIdXmlIter++) {
				const SmartPtrCXmlElement pmeIdXml = pmeIdXmlIter->second;

				const std::string pmeIdDoc = pmeIdXml->getValue();

				pmeIdVal.push_back(pmeIdDoc);
			}
		}

		pmeIdCollectionDoc.CreateInstance();
		pmeIdCollectionDoc->initialize(
			pmeIdVal);
	}
	CAF_CM_EXIT;

	return pmeIdCollectionDoc;
}

