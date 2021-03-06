#include "SamiOrganizationsApi.h"

#include "SamiHelpers.h"
#include "SamiError.h"

using namespace Tizen::Base;

namespace Swagger {


SamiOrganizationsApi::SamiOrganizationsApi() {

}

SamiOrganizationsApi::~SamiOrganizationsApi() {

}

void
v1OrganizationsOrganizationIdUsersPostProcessor(HttpResponse* pHttpResponse, void (* handler)(void*, SamiError*)) {
  int code = pHttpResponse->GetHttpStatusCode();

  if(code >= 200 && code < 300) {
    ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
    IJsonValue* pJson = JsonParser::ParseN(*pBuffer);

    SamiUserTokenSuccessfulResponse* out = new SamiUserTokenSuccessfulResponse();
    jsonToValue(out, pJson, L"SamiUserTokenSuccessfulResponse*", L"SamiUserTokenSuccessfulResponse");

    if (pJson) {
      if (pJson->GetType() == JSON_TYPE_OBJECT) {
         JsonObject* pObject = static_cast< JsonObject* >(pJson);
         pObject->RemoveAll(true);
      }
      else if (pJson->GetType() == JSON_TYPE_ARRAY) {
         JsonArray* pArray = static_cast< JsonArray* >(pJson);
         pArray->RemoveAll(true);
      }
      handler(out, null);
    }
    else {
      SamiError* error = new SamiError(0, new String(L"No parsable response received"));
      handler(null, error);
    }
    
  }
  else {
    SamiError* error = new SamiError(code, new String(pHttpResponse->GetStatusText()));
    handler(null, error);
    
  }
}

SamiUserTokenSuccessfulResponse* 
SamiOrganizationsApi::v1OrganizationsOrganizationIdUsersPostWithCompletion(Integer* organizationId, SamiUserTokenRequest* body, String* accessToken, void (* success)(SamiUserTokenSuccessfulResponse*, SamiError*)) {
  client = new SamiApiClient();

  client->success(&v1OrganizationsOrganizationIdUsersPostProcessor, (void(*)(void*, SamiError*))success);
  HashMap* headerParams = new HashMap(SingleObjectDeleter);
  headerParams->Construct();

  
  HashMap* queryParams = new HashMap(SingleObjectDeleter);
  queryParams->Construct();

  
    queryParams->Add(new String("access_token"), accessToken);

  String* mBody = null;

  if(body != null) {
    mBody = new String(body->asJson());
    headerParams->Add(new String("Content-Type"), new String("application/json"));
  }

  String url(L"/v1/organizations/{organizationId}/users");

  String s_organizationId(L"{");
  s_organizationId.Append(L"organizationId");
  s_organizationId.Append(L"}");
  url.Replace(s_organizationId, stringify(organizationId, L"Integer*"));

  client->execute(SamiOrganizationsApi::getBasePath(), url, "POST", (IMap*)queryParams, mBody, (IMap*)headerParams, null, L"application/json");
  return null;
}


} /* namespace Swagger */
