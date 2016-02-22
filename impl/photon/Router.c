#include "photon/Router.h"
#include "photon/PhotonGcMain.h"

#include <string.h>

//TODO: define constants

static PhotonGtRoute _routerRoutesArray[256];
static PhotonGtArrRoute _routerRoutes;
static PhotonGtRoute _routerGroupRoutesArray[256];
static PhotonGtArrRoute _routerGroupRoutes;

void PhotonRouter_Init()
{
    _routerRoutes.size = 0;
    _routerRoutes.data = &_routerRoutesArray[0];
    _routerGroupRoutes.size = 0;
    _routerGroupRoutes.data = &_routerGroupRoutesArray[0];
}

void PhotonRouter_ClearRoutes()
{
    _routerRoutes.size = 0;
}

void PhotonRouter_ClearGroupRoutes()
{
    _routerGroupRoutes.size = 0;
}

static PhotonGtRouterError setRoute(PhotonGtArrRoute* routes, PhotonGtAddress address, PhotonGtAddress nextHop)
{
    if (address == nextHop) {
        return PHOTON_GT_ROUTER_ERROR_CANNOUT_ROUTE;
    }

    size_t i;
    for (i = 0; i < routes->size; i++) {
        PhotonGtRoute* route = &routes->data[i];
        if (route->destination_address == address) {
            route->next_hop = nextHop;
            return PHOTON_GT_ROUTER_ERROR_OK;
        }
    };

    if (i == 256) {
        return PHOTON_GT_ROUTER_ERROR_MAXIMUM_ROUTES_REACHED;
    }

    PhotonGtRoute* route = &routes->data[i];
    route->destination_address = address;
    route->next_hop = nextHop;
    routes->size++;

    return PHOTON_GT_ROUTER_ERROR_OK;
}

static PhotonGtRouterError getNextHop(const PhotonGtArrRoute* routes, PhotonGtAddress address,
                                      PhotonGtAddress* nextHop)
{
    for (size_t i = 0; i < routes->size; i++) {
        PhotonGtRoute* route = &routes->data[i];
        if (route->destination_address == address) {
            *nextHop = route->next_hop;
            return PHOTON_GT_ROUTER_ERROR_OK;
        }
    };
    return PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS;
}

static PhotonGtRouterError delRoute(PhotonGtArrRoute* routes, PhotonGtAddress address)
{
     for (size_t i = 0; i < routes->size; i++) {
        PhotonGtRoute* route = &routes->data[i];
        if (route->destination_address == address) {
            memmove(route, route + 1, (routes->size - i - 1) * sizeof(routes->data[i]));
            routes->size--;
            return PHOTON_GT_ROUTER_ERROR_OK;
        }
    };
    return PHOTON_GT_ROUTER_ERROR_NO_SUCH_ADDRESS;
}

PhotonGtRouterError PhotonRouter_GetNextHop(PhotonGtAddress address, PhotonGtAddress* nextHop)
{
    return getNextHop(&_routerRoutes, address, nextHop);
}

PhotonGtRouterError PhotonRouter_GetNextGroupHop(PhotonGtAddress address, PhotonGtAddress* nextHop)
{
    return getNextHop(&_routerGroupRoutes, address, nextHop);
}

PhotonGtRouterError PhotonRouter_SetRoute(PhotonGtAddress address, PhotonGtAddress nextHop)
{
    return setRoute(&_routerRoutes, address, nextHop);
}

PhotonGtRouterError PhotonRouter_DelRoute(PhotonGtAddress address)
{
    return delRoute(&_routerRoutes, address);
}

PhotonGtRouterError PhotonRouter_SetGroupRoute(PhotonGtAddress groupAddress, PhotonGtAddress nextHop)
{
    return setRoute(&_routerGroupRoutes, groupAddress, nextHop);
}

PhotonGtRouterError PhotonRouter_DelGroupRoute(PhotonGtAddress groupAddress)
{
    return delRoute(&_routerGroupRoutes, groupAddress);
}

PhotonGtRouterError PhotonGcMain_RouterSetRoute(PhotonGtAddress address, PhotonGtAddress nextHop)
{
    return PhotonRouter_SetRoute(address, nextHop);
}

PhotonGtRouterError PhotonGcMain_RouterDelRoute(PhotonGtAddress address)
{
    return PhotonRouter_DelRoute(address);
}

PhotonGtRouterError PhotonGcMain_RouterSetGroupRoute(PhotonGtAddress groupAddress, PhotonGtAddress nextHop)
{
    return PhotonRouter_SetGroupRoute(groupAddress, nextHop);
}

PhotonGtRouterError PhotonGcMain_RouterDelGroupRoute(PhotonGtAddress groupAddress)
{
    return PhotonRouter_DelGroupRoute(groupAddress);
}

PhotonGtArrRoute PhotonGcMain_RouterRoutes()
{
    return _routerRoutes;
}

PhotonGtArrRoute PhotonGcMain_RouterGroupRoutes()
{
    return _routerGroupRoutes;
}
