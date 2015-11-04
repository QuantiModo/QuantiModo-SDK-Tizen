/*
 * SamiInline_response_200_7.h
 * 
 * 
 */

#ifndef SamiInline_response_200_7_H_
#define SamiInline_response_200_7_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FWebJson.h>
#include "SamiHelpers.h"
#include "SamiObject.h"

using namespace Tizen::Web::Json;


#include "SamiCorrelation.h"
using Tizen::Base::Collection::IList;
using Tizen::Base::Boolean;


namespace Swagger {

class SamiInline_response_200_7: public SamiObject {
public:
    SamiInline_response_200_7();
    SamiInline_response_200_7(String* json);
    virtual ~SamiInline_response_200_7();

    void init();

    void cleanup();

    String asJson ();

    JsonObject* asJsonObject();

    void fromJsonObject(IJsonValue* json);

    SamiInline_response_200_7* fromJson(String* obj);

    
    IList* getPData();
    void setPData(IList* pData);
    
    Boolean* getPSuccess();
    void setPSuccess(Boolean* pSuccess);
    

private:
    IList* pData;
    Boolean* pSuccess;
    
};

} /* namespace Swagger */

#endif /* SamiInline_response_200_7_H_ */